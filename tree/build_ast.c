/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:25:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/23 11:40:34 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void branchout_tree(t_tree *node);

/* >>> build_ast
Purpose: Based on the token, build Abstract Syntax Tree (AST)

=========================================================================
Precedence - tree branchout following this order
1) Combine operator
2) Subshell operator
Else: Default is EXE

*/
void build_ast(t_shell *data)
{
    merge_redirect(data->token);
    data->tree = create_tree(data->token);
    branchout_tree(data->tree);
}

static void branchout_tree(t_tree *node)
{
    if (!node)
        return ;
    if (branch_combine(node)) 
    {
        branchout_tree(node->left);
        branchout_tree(node->right);
    }
    else if (branch_subshell(node))
        branchout_tree(node->left);
    else 
        node->type = EXE;
}