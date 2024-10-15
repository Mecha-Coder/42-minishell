/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:49 by jetan             #+#    #+#             */
/*   Updated: 2024/10/15 15:28:20 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_name(char *name)
{
	int	i;
	
	if (ft_strcmp(name[0], "$") == 0)
		return (0);
	i = 0;
	while (name[++i])
	{
		if (ft_strcmp(name[i], "=") == 0)
			return (0);	
	}
	return (1);
}

/* this function check the argument match with env variable
 * 
*/
void	builtin_unset(char **av, t_env **env)//haven't finish
{
	int	i;
	
	i = -1;
	while (av[++i])
	{
		if ()
			
		= ->next;
	}
}

update_env()