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

void	echo(char **av)
{
	int	i;
	int	new_line;
	
	i = 1;
	new_line = 1;
	while (av[i] != NULL && n_option(av[i]))
	{
		new_line = 0;
		i++;
	}
	while (av[i])
	{	
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
}
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	builtin_echo(av);
// }