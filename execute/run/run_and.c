/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:21:38 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 17:59:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void run_and(t_tree *node, t_shell *data)
{
    descent_tree(node->left, data);
    if (data->cmd_exit_no)
        return ;
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
        close(node->pipe[1]);
    }
    descent_tree(node->right, data);
}