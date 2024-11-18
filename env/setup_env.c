/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:02 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 14:43:02 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_env	*create_env_node(char *s);
static char		*extract_key(char *s, int i);
static char		*extract_val(char *s, int i);

/* >>> setup_env
Purpose: Setup a local env which is a copy of the envp in main(). 
		 Store them inside a key/value struct linked-list.
=======================================================================
Return: NONE
*/

void	setup_env(t_shell *data, char **env)
{
	int		i;
	t_env	*current;

	i = 0;
	data->env = create_env_node(env[i]);
	current = data->env;
	while (env[++i])
	{
		current->next = create_env_node(env[i]);
		current = current->next;
	}
}

static t_env	*create_env_node(char *s)
{
	t_env	*new;
	int		i;

	i = 0;
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
	{
		perror("Malloc fail");
		exit(EXIT_FAILURE);
	}
	while (s && s[i] != '=')
		i++;
	new->key = extract_key(s, i);
	new->val = extract_val(s, i + 1);
	new->next = NULL;
	return (new);
}

static char	*extract_key(char *s, int i)
{
	char	*key;

	key = (char *)malloc(i + 1);
	if (!key)
	{
		perror("Malloc fail");
		exit(EXIT_FAILURE);
	}
	key[i] = '\0';
	while (--i > -1)
		key[i] = s[i];
	return (key);
}

static char	*extract_val(char *s, int i)
{
	char	*val;

	s = s + i;
	i = ft_strlen(s);
	val = (char *)malloc(i + 1);
	if (!val)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	val[i] = '\0';
	while (--i > -1)
		val[i] = s[i];
	return (val);
}

/* Test
int main(int ac, char **av, char **env)
{
	t_shell data;
	(void)ac;
	(void)av;

	setup_env(&data, env);
	show_env(&data);
	clear_env(&data);
}
*/