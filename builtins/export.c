/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:34 by jetan             #+#    #+#             */
/*   Updated: 2024/10/18 14:37:05 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_name(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0])) && str[0] != '_')
		return (0);
	i = 0;	
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
	}
	return (1);
}

void	builtin_export(char **args, t_env *env)
{
	int	i;
	
	if (!args[1])
	{
		
		return;
	}
	i = 0;
	while (args[++i])
	{
		if (!valid_name(args[i]))
		{
			
		}
		if (ft_strchr(args[i], '='))
			add_update_env(args[i], env)
		
	}
}

int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    create_env(&data, env);
    builtin_env(&data);
    destroy_env(&data);
    return 0;
}