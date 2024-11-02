/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/11/02 16:08:45 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	cd_previous_dir(t_shell *data)
{
	char	*oldpwd;
	
	oldpwd = getenv("OLDPWD");
	if (!oldpwd)
	{
		error_msg("cd", "OLDPWD not set");
		return;
	}
	if (chdir(oldpwd) == -1)
	{
		perror("cd");
		return;
	}
	printf("%s", oldpwd);
	update_pwd(data);
}

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

void	cd(char **av, t_shell *data)
{
	arg_count(av, "cd");
	if (!av[1])//no argument
		cd_home(data);
	else if (ft_strcmp(av[1], "-") == 0)
		cd_previous_dir();
	else
		cd_relative_and_absolute(data, av[1]);
}

int	main(int ac, char **av)
{
	(void) ac;
	// builtin_cd(av);
	// cd_previous();
	// cd_home();
}