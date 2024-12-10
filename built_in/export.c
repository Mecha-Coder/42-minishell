/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:42:54 by jetan             #+#    #+#             */
/*   Updated: 2024/11/13 17:42:54 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	process_var(char *s, t_env *env, int *track);
static void	print_sorted_env(t_env *env);
static char	**env_key_list(t_env *env);
static void	sort_list(char **list);

/* >>> export
Description: Update or append variable inside env
==========================================================================
Steps:
- arg = 0   | print all var in env in accending order
- arg > 0 
       ↓                      ↓         ↓
	VAR='new value'\0    TEST\0    INPUT=\0
    ---                  ----      -----	
    Check
	- str before '=' or '/0' is valid identifier | else prompt error
    - if correct, must have '=' after that       | else ignore
    Proceed
    - If key exist in env, amend value
    - Else,  add new variable into the env

*/
int	ft_export(char **arg, t_shell *data)
{
	int	i;
	int	track;

	i = 0;
	track = 0;
	if (arg[1] == NULL)
	{
		print_sorted_env(data->env);
		return (EXIT_SUCCESS);
	}
	while (arg[++i])
	{
		if (!process_var(arg[i], data->env, &track) && ++track)
			err_msg_1("export", arg[i], "fail to add into env");
	}
	if (track)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	process_var(char *s, t_env *env, int *track)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '=' && s[i] != '\0')
	{
		i++;
		count++;
	}
	i = 0;
	if ((is_identifier(s, &i) != count || !count) && ++(*track))
		err_msg_1("export", s, "not a valid identifier");
	else if (s[i] == '=')
	{
		s[i] = '\0';
		if (env_val(s, env))
			return (update_env(s, &s[i + 1], env));
		else
			return (append_env(s, &s[i + 1], env));
	}
	return (TRUE);
}

static void	print_sorted_env(t_env *env)
{
	int		i;
	char	**list;

	i = -1;
	list = env_key_list(env);
	sort_list(list);
	while (list[++i])
		ft_printf("declare -x %s=\"%s\"\n", list[i], env_val(list[i], env));
	free(list);
}

static char	**env_key_list(t_env *env)
{
	int		i;
	char	**list;

	i = 0;
	list = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
	if (!list)
		err_exit("malloc", errno);
	while (env)
	{
		list[i++] = env->key;
		env = env->next;
	}
	list[i] = NULL;
	return (list);
}

static void	sort_list(char **list)
{
	char	*temp;
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (list && list[len])
		len++;
	while (--len)
	{
		i = -1;
		while (++i < len)
		{
			if (ft_strcmp(list[i], list[i + 1]) > 0)
			{
				temp = list[i + 1];
				list[i + 1] = list[i];
				list[i] = temp;
			}
		}
	}
}
