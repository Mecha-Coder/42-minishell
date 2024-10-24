/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:31 by jetan             #+#    #+#             */
/*   Updated: 2024/10/24 14:04:06 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
			return (1);
	else if (ft_strcmp(cmd, "export") == 0)
			return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
			return (1);
	else if (ft_strcmp(cmd, "env") == 0)
			return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
			return (1);
	return (0);
}

void	exec_builtins(t_tree *node, t_env *env)
{
	if (ft_strcmp(node->cmd[0], "echo") == 0)
		builtin_echo(->cmd);
	else if (ft_strcmp(node->cmd[0], "cd") == 0)
		builtin_cd(->cmd);
	else if (ft_strcmp(node->cmd[0], "pwd") == 0)
		builtin_pwd(->cmd);
	else if (ft_strcmp(node->cmd[0], "export") == 0)
		builtin_export(->cmd);
	else if (ft_strcmp(node->cmd[0], "unset") == 0)
		builtin_unset(->cmd);
	else if (ft_strcmp(node->cmd[0], "env") == 0)
		builtin_env(env);
	else if (ft_strcmp(node->cmd[0], "exit") == 0)
		builtin_exit(->cmd);
}