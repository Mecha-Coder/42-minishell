/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:34 by jetan             #+#    #+#             */
/*   Updated: 2024/10/20 16:52:42 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_existing_env(t_env **env, char *key, char *val)
{
	t_env	*current;
	t_env	*new_node;
	
	current = *env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->val);
			current->val = val;
			free(key);
		}
		current = current->next;
	}
	new_node = create_env_node(val);
	if (new_node)
	{
		new_node->next = *env;
		*env = new_node;
	}
}

void	export_env(char *var, t_env **env)
{
	int	i;
	char	*key;
	char	*val;
	
	while (var[i] && var[i] != '=')
		i++;
	key = extract_key(var, i);
	if (var[i] == '=')
		val = extract_val(var, i + 1);
	else
		val = NULL;
	update_existing_env(env, key, val);
}

int	valid_name(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0])) && str[0] != '_')
		return (0);
	i = 0;	
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
	}
	return (1);
}

void	builtin_export(char **args, t_env **env)
{
	int	i;
	
	if (!args[1])
	{
		print_sorted_env(env);
		return;
	}
	i = 0;
	while (args[++i])
	{
		if (!valid_name(args[i]))
		{
			
		}
		export_env(args[i], env);
	}
}

int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    create_env(&data, env);
    builtin_env(&data);
    destroy_env(&data);
    return 0;
}