/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:12:19 by jetan             #+#    #+#             */
/*   Updated: 2024/11/05 15:56:02 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(char **args, t_shell *data)
{
	int		i;
	t_env	*current;

	i = -1;
	while (args[++i])
	{
		if (ft_strcmp(args[i], "env"))
		{
			err_msg_3("env", "too many arguments");
			return (EXIT_FAILURE);
		}
	}
	current = data->env;
	while (current)
	{
		ft_printf("%s=%s\n", current->key, current->val);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

/*
int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    create_env(&data, env);
    ft_env(av, &data);
    destroy_env(&data);
    return 0;
}
*/
