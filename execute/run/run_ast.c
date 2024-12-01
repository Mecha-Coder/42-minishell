/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:56 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 18:49:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void descent_tree(t_tree *node, t_shell *data)
{
    if      (node->type == EXE)   run_exe(node, data);
    else if (node->type == PIPE)  run_pipe(node, data);
    else if (node->type == SUB)   run_subshell(node, data);
    else if (node->type == AND)   run_and(node, data);
    else if (node->type == OR)    run_or(node, data);
    if (node->terminate)
        exit(data->cmd_exit_no);
}

void run_ast(t_shell *data)
{
    descent_tree(data->tree, data);
}
