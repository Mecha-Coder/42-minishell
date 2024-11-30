/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:29:13 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:09:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int run_subshell(t_tree *node, t_shell *data)
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
        return (manage_io(io, FALSE), WEXITSTATUS(status));
    }
    return (manage_io(io, FALSE), EXIT_FAILURE);
}