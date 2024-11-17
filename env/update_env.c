/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:45:20 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:45:20 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	update_env(char *key, char *val, t_env *env)
{
	char	*temp;

	while (env && ft_strcmp(key, env->key))
		env = env->next;
	temp = ft_strdup(val);
	if (temp)
	{
		free(env->val);
		env->val = temp;
		return (TRUE);
	}
	return (FALSE);
}
