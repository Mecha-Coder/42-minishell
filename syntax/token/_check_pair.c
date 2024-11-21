/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:33:23 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 13:25:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define SUB_ERR_1 "Invalid operator after bracket"
#define SUB_ERR_2 "Wrong usage of subshell operator"

/* >>> check_pair
Purpose: Check OB and CB left right side meet rule
===============================================================
Rule
-     <START><COMBINE OPT> ( 

-                    <!OB> ) <COMBINE><REDIRECT><END>

-                  !  <OB> ()  <CB>
NOTE: 
- <COMBINE OPT> = || , | , &&
- Is <END> when type = 0
- Is <START> when ob_index = 0 
===============================================================
Return
    TRUE : Both pair meet above rule
    FALS : vice vesa
*/

int check_pair(t_sub *sub, int ob, int cb, char *input)
{
    int i;
    int type;

    (i = -1, type = 0);
    if (ob && sub[ob - 1].type > 3)   
        i = sub[ob].input_index;
    else if (sub[cb + 1].type > 3 && ++type)
        i = sub[cb + 1].input_index;
    else if (sub[ob + 1].type != STR && sub[ob + 1].type != OB && ++type) 
        i = sub[ob + 1].input_index;
    else if (sub[cb - 1].type != STR && sub[cb - 1].type != CB)
        i = sub[cb].input_index;
    if (i >= 0)
    {
        if (type)
            err_msg_syntax(input, SUB_ERR_1, i);
        else
            err_msg_syntax(input, SUB_ERR_2, i);
        return (FALSE);
    }
    return (TRUE);
}