/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:59:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:12:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void prompt_heredoc(int *fd, char *delimiter);

/* >>>run_heredoc
Purpose: Responsible to run through the tree and get heredoc input 
*/
void run_heredoc(t_tree *node)
{
    t_token *current;

    if (!node)
        return;
    current = node->token;
    while (current)
    {
        if (current->type == HERE)
            prompt_heredoc(current->herefd, current->content);
        current = current->next;
    }
    run_heredoc(node->left);
    run_heredoc(node->right);
}

static void prompt_heredoc(int *fd, char *delimiter)
{
    char *input;

    if (pipe(fd) < 0) 
        err_exit("pipe", errno);
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