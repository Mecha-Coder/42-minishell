/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _find_bracket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:20:31 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 12:06:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> find_bracket_pair                          
Purpose: Find the 1st occurance of bracket pair

==========================================================================
Example
   
 ob_index=0         cb_index=20
    ↓                   ↓
    (echo hello  && (ls)) || (ech0 next)
    012345678901234567890

==========================================================================
Param
- t_sub *sub  : token_array (behave like string)
- int ob & cd : reference pointer to 2 integer variable in parent
                to indicate the index location of OB and CB

==========================================================================
Side effect
- Updates the *ob & *cd value to be used by parent

==========================================================================
Return
  TRUE  : Found outermost bracket group pair
  FALSE : Not found
*/
int find_pair(t_sub *sub, int *ob, int *cb)
{
    int i;
    int count;

    (i = -1, count = 0);
    while (sub[++i].type)
    {
        if (sub[i].type == OB)
        {
            if (!count)
                *ob = i;
            count++;
        }
        else if (sub[i].type == CB && !(--count))
        {
            *cb = i;
            return (TRUE);
        }
    }
    return (FALSE);
}