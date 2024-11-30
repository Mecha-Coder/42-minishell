/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:00:22 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 10:10:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int execute(char **args, t_shell *data)
{
    int status;

    if      (!ft_strcmp(args[0], "pwd"))    status = ft_pwd();
    else if (!ft_strcmp(args[0], "clear"))  status = ft_clear();
    else if (!ft_strcmp(args[0], "echo"))   status = ft_echo(args);
    else if (!ft_strcmp(args[0], "export")) status = ft_export(args, data);
    else if (!ft_strcmp(args[0], "unset"))  status = ft_unset(args, data);
    else if (!ft_strcmp(args[0], "cd"))     status = ft_cd(args, data);
    else if (!ft_strcmp(args[0], "env"))    status = ft_env(args, data);
    else if (!ft_strcmp(args[0], "exit"))   status = ft_exit(args, data);
    else                                    status = none_builtin(args, data->env);
    return (status);
}

int run_exe(t_tree *node, t_shell *data)
{
    char **args;
    int status;
    int io[2];

    manage_io(io, TRUE);
    if (expansion(node, data) && do_redirect(node->token))
    {
        args = prep_arg(node->token);
        status = EXIT_SUCCESS;
        if (args)
        {
            status = execute(args, data);
            free(args);
        }
        return (manage_io(io, FALSE), status);
    }
    return (manage_io(io, FALSE), EXIT_FAILURE);
}
