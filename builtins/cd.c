/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:56 by jetan             #+#    #+#             */
/*   Updated: 2024/10/11 17:23:21 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	cd_previous()
{
	char	*oldpwd;
	
	oldpwd = getenv("OLDPWD");
	if (chdir(oldpwd))
	{
		printf("%s", oldpwd);
	}
}

void	cd_home()
{
	char	*home;
	
	home = getenv("HOME");	
	if (!home)
	{
		error_msg("cd", "Home not set");
		return;
	}
	chdir(home);
}

void	builtin_cd(char **av)
{
	
	arg_count(av, "cd");
	if (!av[1])//no argument
		cd_home();
	else if (av[1] == '-')
		cd_previous();
	else if ()
}

int	main(int ac, char **av)
{
	(void) ac;
	// builtin_cd(av);
	// cd_previous();
	cd_home();
}