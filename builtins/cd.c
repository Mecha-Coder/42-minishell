/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/11/03 18:13:50 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	update_oldpwd(t_shell *data)
{
	char	cwd[1024];
	t_env	*current;

	current = data->env;
	while (current)
	{
		if (ft_strcmp(current->key, "OLDPWD") == 0)
		{
			free(current->val);
			current->val = ft_strdup(cwd);
			return;
		}
		current = current->next;
	}
}

void	update_pwd(t_shell *data)
{
	char	cwd[1024];
	t_env	*current;
	
	current = data->env;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd error");
		return;
	}
	while (current)
	{
		if (ft_strcmp(current->key ,"PWD") == 0)
		{
			free(current->val);
			current->val = ft_strdup(cwd);
			return;
		}
		current = current->next;
	}
}

// void	cd_previous_dir(t_shell *data)
// {
// 	char	*oldpwd;
	
// 	oldpwd = getenv("OLDPWD");
// 	if (!oldpwd)
// 	{
// 		error_msg("cd", "OLDPWD not set");
// 		return;
// 	}
// 	if (chdir(oldpwd) == -1)
// 	{
// 		perror("cd");
// 		return;
// 	}
// 	printf("%s", oldpwd);
// 	update_pwd(data);
// }

void	cd_home(t_shell *data)
{
	char	*home;
	
	home = getenv("HOME");	
	if (!home)
	{
		error_msg("cd", "Home not set");
		return;
	}
	if (chdir(home) == -1)
	{
		perror("cd");
		return;
	}
	update_pwd(data);
}

void	ft_cd(char **args, t_shell *data)
{
	arg_count(args, "cd");
	if (!args[1] || ft_strcmp(args[1], "~") == 0)
		cd_home(data);
	else
	{
		update_oldpwd(data);
		if (chdir(args[1]) == -1)
		{
		
			perror("cd");
			return;
		}
	}
	update_pwd(data);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_shell data;
	char *args[] = {"/path/to/directory", NULL};
	t_env env1 = {"PWD", ft_strdup("/initial/path"), NULL};
	data.env = &env1;
	// Initialize data and environment variables here
	// For example, you might want to set up the data.env linked list
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working dir: %s\n", cwd);
	} else {
		perror("getcwd() error");
	}

	ft_cd(av, &data);

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working dir: %s\n", cwd);
	} else {
		perror("getcwd() error");
	}
	return 0;
}*/
