/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:36:26 by jetan             #+#    #+#             */
/*   Updated: 2024/10/24 14:22:46 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	right(int fd)
{
	int	exit_status;
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else
	{
		waitpid(pid, &exit_status, 0);
		close(fd[1]);
	}
	return (exit_status);
}

int	left(int fd)
{
	int	exit_status;
	pid_t	pid;
	
	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else
	{
		waitpid(pid, &exit_status, 0);
		close(fd[1]);
	}
	return (exit_status);
}

exec_pipe()
{
	int	fd[2];

	if (pid < 0)
		printf();
	left(fd, );
	exit_code = right(fd, );
}

void	exec_cmd(t_tree *node, t_env *env)
{
	pid_t	pid;
	
	if (!node)
		return;
	if (is_builtin(node->cmd[0]))
		execute_builtin(node, env);
	else
	{
		pid = fork;
		if (pid == 0)
		{
			execve(node->cmd[0], node->cmd, convert_env_array(env));
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
}
