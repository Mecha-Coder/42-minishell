/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:12:19 by jetan             #+#    #+#             */
/*   Updated: 2024/11/02 15:46:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_shell *data)
{
	t_env	*current;
	
	current = data->env;
	while (current)
	{
		printf("%s=%s\n", current->key, current->val);
		current = current->next;
	}
}

// int main(int ac, char **av, char **env)
// {
//     t_shell data;
//     (void)ac;
//     (void)av;

//     create_env(&data, env);
//     builtin_env(&data);
//     destroy_env(&data);
//     return 0;
// }