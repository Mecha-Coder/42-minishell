/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:59:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/05 16:59:07 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void prompt_heredoc(int *fd, char *delimiter);

/* >>>run_heredoc
Purpose: Responsible to run through the tree and get heredoc input 
*/
// void run_heredoc(t_tree *node)
// {
//     t_token *current;
//
//     if (!node)
//         return;
//current = node->token;
//     while (current)
//     {
//         if (current->type == HERE)
//             prompt_heredoc(current->herefd, current->content);
//         current = current->next;
//     }
//     run_heredoc(node->left);
//     run_heredoc(node->right);
// }
int run_heredoc(t_tree *node)
{
	t_token *current;
	pid_t pid;
	int status = 0;
	
	if (!node)
		return (0);
	current = node->token;
	while (current)
	{
		if (current->type == HERE)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				exit(1);
			}
			else if (pid == 0)
			{
				// signal(SIGINT, heredoc_handler);
				signal(SIGINT, SIG_DFL);
				prompt_heredoc(current->herefd, current->content);
				exit(0); // Ensure child process exits after running prompt_heredoc
			}
			else
			{
				// Parent process
				signal(SIGINT, sigint_handler_child);
				waitpid(pid, &status, 0); // Wait for child to finish
				if (WIFSIGNALED(status))
				{
					// data->cmd_exit_no = WTERMSIG(status) + 128;
					return (1);
				}
			}
		}
		current = current->next;
	}
	if (run_heredoc(node->left))
		return (1);
	if (run_heredoc(node->right))
		return (1);
	return (0);
}

static void prompt_heredoc(int *fd, char *delimiter)
{
	char *input;

	if (pipe(fd) < 0)
	{
		err_exit("pipe", errno);
	}
	while (1) 
	{
		input = readline("> ");
		if (!input)
		{
			err_msg_5(delimiter);
			return ; 
		}
		if (!ft_strcmp(input, delimiter))
		{
			free(input);
			return ;
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
}
/*
int main()
{
	int herefd[2];
	int bytes_read;
	char buffer[1024];

	prompt_heredoc(herefd, "Hello");

	printf("Print Output\n=============\n");
	close(herefd[1]);
	while ((bytes_read = read(herefd[0], buffer, sizeof(buffer))) > 0)
		write(STDOUT_FILENO, buffer, bytes_read);
	close(herefd[0]);
}
*/

/*
int main()
{
	t_shell data;

	char s[] = "<< EOF cat | echo \"Hello\" || 
		(echo Nice << DOOM) > file/out << YES  && ls << DONE  << OK";

	data.input = s;
	tokenize(&data);
	build_ast(&data);
	show_tree(data.tree, 0);
	run_heredoc(data.tree);
	destroy_tree(data.tree);
}
*/
