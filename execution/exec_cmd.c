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

left

exec_pipe()
{
	int	fd[2];

	left();
	exit_code = right();
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
