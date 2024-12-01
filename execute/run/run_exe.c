/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:00:22 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 19:00:16 by jpaul            ###   ########.fr       */
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

void run_exe(t_tree *node, t_shell *data)
{
    char **args;
    int io[2];

    manage_io(io, TRUE);
    if (expansion(node, data) && do_redirect(node->token))
    {
        args = prep_arg(node->token);
        if (args)
        {
            data->cmd_exit_no = execute(args, data);
            free(args);
        }
        else
            data->cmd_exit_no = EXIT_SUCCESS;
    }
    else
        data->cmd_exit_no = EXIT_FAILURE;
    manage_io(io, FALSE);
}
