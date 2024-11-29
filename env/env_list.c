/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:50 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:40:50 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*concat_key_val(char *s, t_env *env);

/* >>> env_array
Description: Convert env(linked-list) to 2D array
=====================================================================
Param: Pointer to env linked-list head
	key: USER
	val: jpaul
=====================================================================
Return: 2D array version of the env
	* array = {"USER=jpaul", NULL}
	* NULL if malloc fail
*/

char	**env_list(t_env *env)
{
	int		i;
	int		total;
	char	*s;
	char	**list;

	i = 0;
	list = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
	if (!list)
		err_exit("malloc", errno);
	while (env)
	{
		total = ft_strlen(env->key) + ft_strlen(env->val) + 2;
		s = (char *)malloc(total);
		if (!s)
			return (free_list(list), NULL);
		list[i++] = concat_key_val(s, env);
		env = env->next;
	}
	list[i] = NULL;
	return (list);
}

static char	*concat_key_val(char *s, t_env *env)
{
	ft_strcpy(s, env->key);
	ft_strcat(s, "=");
	ft_strcat(s, env->val);
	return (s);
}

/* Test
int main()
{
	char **list;
	int i = -1;

	t_env n1;
	t_env n2;
	t_env n3;

	n1.key = "HOME";
	n1.val = "/home/jpaul";
	n1.next = &n2;

	n2.key = "USER";
	n2.val = "Jason";
	n2.next = &n3;

	n3.key = "SHELL";
	n3.val = "/bash/";
	n3.next = NULL;

	list = env_array(&n1);
	while (list && list[++i]) 
		printf("%s\n", list[i]);
	free_list(list);
}
*/