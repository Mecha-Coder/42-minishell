/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:31 by jetan             #+#    #+#             */
/*   Updated: 2024/10/22 23:18:29 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_builtins(t_tree *node, t_env *env)
{
	if (ft_strcmp(node->cmd[0], "echo") == 0)
		builtin_echo();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();
	else if (ft_strcmp(node->cmd[0], "") == 0)
		builtin_();

}