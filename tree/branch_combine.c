/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_combine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:37:36 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/23 11:56:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void branch(t_tree *node, t_token *release);

/* >>> branch_combine
Purpose:
- Used in building AST. Branch accordingly when encountered combine opt
========================================================================
Method
-                              <---------
- Scan token inside node from right to left (skip those inside bracket)
- When encountered combine operator
    * Update the node type with (operator) found
    * Create left and right child branches
    * Token before (operator) pass to left child node
    * Token after (operator) pass to right child node
    * Disconnect and free combine operator node
*/
int branch_combine(t_tree *node)
{
    t_token *current;
     int bracket;

    bracket = 0;
    current = node->token;
    current = token_jumpfront(current);
    while (current)
    {
        if (current->type == CB)
            bracket++;
        else if (current->type == OB)
            bracket--;
        else if (!bracket && current->type >= 1 && current->type <= 3)
        {
            branch(node, current);
            return (TRUE);
        }
        current = current->prev;
    }
    return (FALSE);
}


static void branch(t_tree *node, t_token *release)
{
    node->type = release->type;
    node->left = create_tree(node->token);
    node->right = create_tree(release->next);
    release->prev->next = NULL;
    release->next->prev = NULL;
    free(release);
    node->token = NULL;
}