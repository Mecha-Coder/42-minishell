/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:38:04 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/15 11:16:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> detection
Purpose:
- To be used by parent function

Task1: track/update state to let parent know
- ON           : can detect meta
- SQ or DQ OFF : don't detect meta

Task2: Return integer
- 0    : Character read is not a quote
- > 0  : What type of quote detected, and whether it's the start or end
=============================================================================
Param:
- char c     : The current reading character by the parent
- int *state : reference pointer to &state from parent function       
=============================================================================
Example

state: ON  |  DQ_OFF   |  ON
           "Hello there"
           ^           ^
return     1000000000003 
=============================================================================
Return:
- 0 : Character read not a quote
- 1 : Read double quote, detection OFF
- 2 : Read single quote, detection OFF
- 3 : Read double quote, detection ON
- 4 : Read single quote, detection ON
=============================================================================
Side effect
- Update the state pointer at child so parent can use it
 * ON (0)
 * SQ_OFF (1)
 * DQ_OFF (2)
*/

int detection(char c, int *state)
{
    if (c == '\"' && *state == ON)     {*state = DQ_OFF; return (1);}
	if (c == '\'' && *state == ON)     {*state = SQ_OFF; return (2);}
	if (c == '\"' && *state == DQ_OFF) {*state = ON; return (3);}
	if (c == '\'' && *state == SQ_OFF) {*state = ON; return (4);}
	return (0);
}