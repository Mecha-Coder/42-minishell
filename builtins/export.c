/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:34 by jetan             #+#    #+#             */
/*   Updated: 2024/10/16 18:04:42 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_update_env(t_env *env)
{
	
}

/* check validate variable name */
int	valid_name(char *name)
{
	int	i;
	
	if (ft_strcmp(name[0], "0123456789") == 0)
		return (0);
	i = 0;
	while (name[++i])
	{
		if (name[i] < 101 && name[i] > 172 && name[i] < 60 && name[i] > 71)
			return (0);
	}
	return (1);
}

// No arguments, print sorted environment
// Iterate over arguments, validate, and update environment
void	builtin_export(char **av, t_env *env)
{
	int	i;
	
	if (!av[1])
		return;
	i = -1;
	while (av[++i])
	{
		if (valid_name(av[i]))
		{
			if (ft_strcmp(av[i], '='))
			{
				add_update_env(av[i], );
			}
			else
			{
				mark_export();
			}
		}
		// else
			//error message
	}	
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	builtin_export(av, env);
}