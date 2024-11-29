/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:21:38 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 10:22:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int run_and(t_tree *node, t_shell *data)
{
    int status;

    status = descent_tree(node->left, data);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
        close(node->pipe[1]);
    }
    if (!status && !descent_tree(node->right, data))
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}