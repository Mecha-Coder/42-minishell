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

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		return (FALSE);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}

int	ft_exit(char **args, t_shell *data)
{
	if (args[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		close_shell(data->cmd_exit_no, data);
	}
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("exit\n", 2);
		err_msg_2("exit", args[1], "numeric argument required");
		close_shell(2, data);
	}
	if (args[2] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		close_shell((unsigned char)ft_atoi(args[1]), data);
	}
	ft_putstr_fd("exit\n", 2);
	arg_count(args, "exit");
	return (EXIT_FAILURE);
}
// int main(int ac, char **av)
// {
// 	t_shell data;
//
// 	data.exit_cmd_no = 23;
// 	(void)ac;
// 	ft_exit(av, &data);
// }
