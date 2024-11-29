/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:56 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 10:20:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int descent_tree(t_tree *node, t_shell *data)
{
    int status;

    if      (node->type == EXE)   status = run_cmd(node, data);
    else if (node->type == PIPE)  status = run_pipe(node, data);
    else if (node->type == SUB)   status = run_subshell(node, data);
    else if (node->type == AND)   status = run_and(node, data);
    else if (node->type == OR)    status = run_or(node, data);
    if (node->terminate)
        exit(status);
    dup2(data->oriterm_fd[STDIN_FILENO], STDIN_FILENO);
    dup2(data->oriterm_fd[STDOUT_FILENO], STDOUT_FILENO);
    return (status);
}

void run_ast(t_shell *data)
{
    data->cmd_exit_no = descent_tree(data->tree, data);
}