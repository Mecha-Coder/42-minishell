/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:40 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 16:01:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> sort_token
Purpose: Sort token based on the index
======================================================================
Extra 
- If input token is not the head. This function will jumpback to 
    head node first before sorting
======================================================================
Return
- t_token * : sorted by index
*/

t_token *sort_token(t_token *current)
{
    int index;
    t_token *master;

    current = token_jumpback(current);
    
}