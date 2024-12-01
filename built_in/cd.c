/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/11/05 17:02:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	update_oldpwd(t_shell *data)
{
	char	cwd[1024];
	t_env	*current;

	current = data->env;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		err_exit("getcwd", errno);
	while (current)
	{
		if (ft_strcmp(current->key, "OLDPWD") == 0)
		{
			free(current->val);
			current->val = ft_strdup(cwd);
			return ;
		}
		current = current->next;
	}
}

static void	update_pwd(t_shell *data)
{
	char	cwd[1024];
	t_env	*current;

	current = data->env;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		err_exit("getcwd", errno);
	while (current)
	{
		if (ft_strcmp(current->key, "PWD") == 0)
		{
			free(current->val);
			current->val = ft_strdup(cwd);
			return ;
		}
		current = current->next;
	}
}

// void	cd_previous_dir(t_shell *data)
// {
// 	char	*oldpwd;
//	
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

static int	cd_home(t_shell *data)
{
	char	*home;

	home = env_val("HOME", data->env);
	if (!home)
	{
		err_msg_3("cd", "HOME not set");
		return (EXIT_FAILURE);
	}
	if (chdir(home) == -1)
	{
		perror("cd");
		return (EXIT_FAILURE);
	}
	update_pwd(data);
	return (EXIT_SUCCESS);
}

int	ft_cd(char **args, t_shell *data)
{
	if (!arg_count(args, "cd"))
		return (EXIT_FAILURE);
	if (!args[1] || ft_strcmp(args[1], "~") == 0)
		return (cd_home(data));
	else
	{
		update_oldpwd(data);
		if (chdir(args[1]) == -1)
		{
			err_msg_2("cd", args[1], "No such file or directory");
			return (EXIT_FAILURE);
		}
	}
	update_pwd(data);
	return (EXIT_SUCCESS);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
// 	t_shell data;
// 	// char *args[] = {"/path/to/directory", NULL};
// 	t_env env1 = {"PWD", ft_strdup("/initial/path"), NULL};
// 	data.env = &env1;
// 	// Initialize data and environment variables here
// 	// For example, you might want to set up the data.env linked list
// 	char cwd[1024 ];

// 	if (getcwd(cwd, sizeof(cwd)) != NULL) {
// 		printf("Current working dir: %s\n", cwd);
// 	} else {
// 		perror("getcwd() error");
// 	}

// 	ft_cd(av, &data);

// 	if (getcwd(cwd, sizeof(cwd)) != NULL) {
// 		printf("Current working dir: %s\n", cwd);
// 	} else {
// 		perror("getcwd() error");
// 	}
// 	return 0;
// }
