/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:19:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:32:40 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child(char **cmd, t_env *list);

/* >>> none_builtin
Purpose: Execute command that is not part of the builtin
*/

int none_builtin(char **cmd, t_env *list)
{
    pid_t id;
    int status;

    id = fork();
    if (id < 0)
        err_exit("fork", errno);
    else if (!id)
        child(cmd, list);
    else
        waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}

void	child(char **cmd, t_env *list)
{
    char **env;
	char *path;

	path = get_path(cmd[0], list);
	if (!path)
	{
		ft_putstr_fd(cmd[0], 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(127);
	}
    env = env_list(list);
	if (execve(path, cmd, env) < 0)
    {
        free_list(env);
	    free(path);
        printf("Fail none_builtin execution");
	    exit(EXIT_FAILURE);
    }
}
