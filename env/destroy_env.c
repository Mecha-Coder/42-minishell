/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:39:15 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:39:15 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	destroy_env(t_shell *data)
{
	t_env	*current;
	t_env	*temp;

	current = data->env;
	while (current)
	{
		if (current->key)
			free(current->key);
		if (current->val)
			free(current->val);
		temp = current->next;
		free(current);
		current = temp;
	}
}
