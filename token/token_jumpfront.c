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

/* >>> token_jumpfront
Purpose: 
- Doesn't matter at which node, 
- This function will move forward to point to token 'tail' node
======================================================================                          
Illustration
-               ↓ --< CURRENT >  
	Token list: node1 ⇋ node2 ⇋ node 3 

-                               ↓ --< MOVE >  
	Token list: node1 ⇋ node2 ⇋ node 3 

Node: Token is a douply linked-list
======================================================================
Return: address of the tail node
*/

t_token	*token_jumpfront(t_token *current)
{
	while (current && current->next)
		current = current->next;
	return (current);
}
