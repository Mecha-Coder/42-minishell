/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:23:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 10:23:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int run_or(t_tree *node, t_shell *data)
{
    int status;

    status = descent_tree(node->left, data);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
        close(node->pipe[1]);
    }
    if (!status || !descent_tree(node->right, data))
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}