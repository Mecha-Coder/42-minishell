/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:29:13 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 18:18:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void run_subshell(t_tree *node, t_shell *data)
{
    int status;
    pid_t id;
    int io[2];

    manage_io(io, TRUE);
    if (expansion(node, data) && do_redirect(node->token))
    {
        node->left->terminate = TRUE;
        id = fork();
        if (id < 0)
            err_exit("fork", errno);
        else if (id == 0)
            descent_tree(node->left, data);
        waitpid(id, &status, 0);
        if (WIFSIGNALED(status))
		    data->cmd_exit_no = WTERMSIG(status) + 128;
        else
            data->cmd_exit_no = WEXITSTATUS(status);
    }
    else
        data->cmd_exit_no = EXIT_FAILURE;
    manage_io(io, FALSE);
}
