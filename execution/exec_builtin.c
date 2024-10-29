/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:44:31 by jetan             #+#    #+#             */
/*   Updated: 2024/10/24 14:11:15 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**convert_env_array(t_env *env)
{
	char	**array;
	int	count;
	t_env	*current;

	while (env)
	{
		count++;
		env = env->next;
	}
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
	{
		perror("malloc failed");
		return NULL;
	}
	current = env;
	while (current)
	{
		array[] = ;
		current = current->next;
	}
	array[] = NULL;
	return (array);
}

void	exec_builtins(t_tree *node, t_env *env)
{
	if (ft_strcmp(node->cmd[0], "echo") == 0)
		builtin_echo(node->cmd);
	else if (ft_strcmp(node->cmd[0], "cd") == 0)
		builtin_cd(node->cmd, env);
	else if (ft_strcmp(node->cmd[0], "pwd") == 0)
		builtin_pwd(node->cmd);
	else if (ft_strcmp(node->cmd[0], "export") == 0)
		builtin_export(node->cmd);
	else if (ft_strcmp(node->cmd[0], "unset") == 0)
		builtin_unset(node->cmd);
	else if (ft_strcmp(node->cmd[0], "env") == 0)
		builtin_env(env);
	else if (ft_strcmp(node->cmd[0], "exit") == 0)
		builtin_exit(node->cmd);
	else
		search_path();
}
