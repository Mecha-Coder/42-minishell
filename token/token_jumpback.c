/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_jumpback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:45:49 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 13:56:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> token_jumpback
Purpose: 
- Doesn't matter at which node, 
- This function will reset to point to token 'head' node
======================================================================                          
Illustration
-                               ↓ --< CURRENT >  
  Token list: node1 ⇋ node2 ⇋ node 3 

-               ↓ --< RESET >  
  Token list: node1 ⇋ node2 ⇋ node 3 

Node: Token is a douply linked-list
======================================================================
Return: address of the head node
*/

t_token *token_jumpback(t_token *current)
{
    while (current && current->prev)
        current = current->prev;
    return (current);
}
