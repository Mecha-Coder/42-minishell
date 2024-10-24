/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:31 by jetan             #+#    #+#             */
/*   Updated: 2024/10/24 09:17:36 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_builtins(t_tree *node, t_env *env)
{
	if (ft_strcmp(node->cmd[0], "echo") == 0)
		builtin_echo();
	else if (ft_strcmp(node->cmd[0], "cd") == 0)
		builtin_cd();
	else if (ft_strcmp(node->cmd[0], "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(node->cmd[0], "export") == 0)
		builtin_export();
	else if (ft_strcmp(node->cmd[0], "unset") == 0)
		builtin_unset();
	else if (ft_strcmp(node->cmd[0], "env") == 0)
		builtin_env();
	else if (ft_strcmp(node->cmd[0], "exit") == 0)
		builtin_exit();
}