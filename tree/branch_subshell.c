/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:11:14 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/23 11:57:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void branch(t_tree *node, t_token *ob, t_token *cb);

/* >>> branch_subshell
Purpose:
- Used in building AST. Branch accordingly when encountered subshell opt
========================================================================
Method
-                              -------->
- Scan token inside node from left to right
- Find OB and CB token pair, once match found
    * Update the node type to SUB
    * Create left child branch
    * Pass the token after ob to left child node
    * The remainding token after cb will be kept in current node
    * Disconnect and free ob and cb token
*/

int branch_subshell(t_tree *node)
{
    t_token *current;
    t_token *ob;
    int bracket;

    bracket = 0;
    current = node->token;
    while (current)
    {
        if (current->type == OB)
        {
            if (!bracket)
                ob = current;
            bracket++;
        }    
        else if (current->type == CB && !(--bracket))
        {
            branch(node, ob, current);
            return (TRUE);
        }
        current = current->next;
    }
    return (FALSE);
}


static void branch(t_tree *node, t_token *ob, t_token *cb)
{
    node->type = SUB;
    node->left = create_tree(ob->next);
    node->token = cb->next;

    ob->next->prev = NULL;
    cb->prev->next = NULL;
    if (cb->next)
        cb->next->prev = NULL;
    free(ob);
    free(cb);
}
