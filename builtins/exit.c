/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/11/04 17:09:40 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_numeric(char *str)
{
	int	i;
	
	i = -1;
	if ((str[0] == '-' || str[0] == '+') && (str[1] != '-' && str[1] != '+'))
		i = 1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	ft_exit(char **args, t_shell *data)
{
	
	if (args[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit(data->exit_cmd_no);
	}
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("exit\n", 2);
		error_arg_msg("exit", args[1], "numeric argument required");
		exit(2);
	}
	if (args[2] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit((unsigned char)ft_atoi(args[1]));
	}
	ft_putstr_fd("exit\n", 2);
	arg_count(args, "exit");
}
int main(int ac, char **av)
{
	t_shell data;
	
	data.exit_cmd_no = 23;
	(void)ac;
	ft_exit(av, &data);
}
