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

    node->left->terminate = TRUE;
    id = fork();
    if (id < 0)
        err_exit("fork", errno);
    else if (id == 0)
        descent_tree(node->left, data);
    waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}