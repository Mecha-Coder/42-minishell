/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:17:06 by jetan             #+#    #+#             */
/*   Updated: 2024/11/02 16:09:40 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	n_option(char *str)
{
	int	i;
	
	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	new_line;
	
	i = 1;
	new_line = 1;
	while (args[i] != NULL && n_option(args[i]))
	{
		new_line = 0;
		i++;
	}
	while (args[i])
	{	
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
	return (EXIT_SUCCESS);
}
// int main(int ac, char **args)
// {
// 	(void)ac;
// 	ft_echo(args);
// }
