/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:12:19 by jetan             #+#    #+#             */
/*   Updated: 2024/11/04 17:08:43 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_env(char **args, t_shell *data)
{
	t_env	*current;
	
	if (args[1])
	{
		printf("too many\n");
		return;
	}
	current = data->env;
	while (current)
	{
		printf("%s=%s\n", current->key, current->val);
		current = current->next;
	}
}

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
