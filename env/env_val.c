/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:42:04 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:42:04 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* eval_val
Description: Search env for that variable(key) and
	return corresponding value

	 USER -> jpaul

Input : Variable name(key) & env linked list 
Output: Value of that variable
	Found     = corresponding value
	Not found = NULL
	NULL key  = NULL

*/
char	*env_val(char *key, t_env *env)
{
	while (key && env)
	{
		if (!ft_strcmp(key, env->key))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}
