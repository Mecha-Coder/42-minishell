/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/11/05 11:12:19 by jpaul            ###   ########.fr       */
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

int	ft_exit(char **args, t_shell *data)
{
	
	if (args[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit(data->cmd_exit_no);
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
	return(EXIT_FAILURE);
}
// int main(int ac, char **av)
// {
// 	t_shell data;
	
// 	data.exit_cmd_no = 23;
// 	(void)ac;
// 	ft_exit(av, &data);
// }
