/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:02:40 by jetan             #+#    #+#             */
/*   Updated: 2024/11/05 15:44:44 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error_msg(char *builtin, char *args)
{
	if (ft_strcmp(builtin, "cd") == 0)
		error_msg1("cd", "Home not set");
	if (ft_strcmp(builtin, "echo") == 0)
		error_msg_export("export", args, "not a valid identifier");
	if (ft_strcmp(builtin, "exit") == 0)
		error_arg_msg("exit", args, "numeric argument required");
}

void	error_msg_export(char *builtin, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("`arg'", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	error_arg_msg(char *builtin, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	error_msg1(char *builtin, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	arg_count(char **args, char *builtin)
{
	int		count;
	
	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		error_msg(builtin, "too many arguments");
		return;
	}
}
