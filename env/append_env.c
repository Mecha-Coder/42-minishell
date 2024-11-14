/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:37:55 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:37:55 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	append_env(char *key, char *val, t_env *env)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (FALSE);
	new->key = ft_strdup(key);
	new->val = ft_strdup(val);
	new->next = NULL;
	if (!new->key || !new->val)
	{
		if (new->key)
			free(new->key);
		if (new->val)
			free(new->key);
		free(new);
		return (FALSE);
	}
	while (env->next)
		env = env->next;
	env->next = new;
	return (TRUE);
}
