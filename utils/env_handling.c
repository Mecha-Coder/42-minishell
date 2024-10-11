/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:14:22 by jetan             #+#    #+#             */
/*   Updated: 2024/10/11 13:35:08 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*create_env_node(char *key, char *val)
{
	t_env	*new_node;
	
	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return NULL;
	new_node->key = key;
	new_node->val = val;
	new_node->next = NULL;
	if (!new_node->key || !new_node->val)
	{
		free(new_node->key);
		free(new_node->val);
		return NULL;
	}
	return (new_node);
}

