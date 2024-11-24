/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_subshell_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:21:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 17:21:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define SUB_ERR_1 "invalid operator after bracket"
#define SUB_ERR_2 "misuse of subshell operator"
#define SUB_ERR_3 "redundant subshell operator"

int redundant_rule(t_pair pair);
int ob_left_rule(t_token *ob_left);
int cb_left_rule(t_token *cb_left);
int cb_right_rule(t_token *cb_right);

/* >>> check_pair
Purpose:
- check if bracket pairs meet rule
- Responsible to print error message if not meeting rule
====================================================================
Rule: 
   OB - check left
   CB - check left & right

<START><COMBINE><OB> (     <!OB> ) <CB><REDIRECT><COMBINE><END> 

Redundant bracket is set as error (())
**************************************
   <OB> (   ) <OTHERS>   or <OTHERS> (   ) <CB> 

   <OB> (   ) <CB>  <----REDUNDANT BRACKET
*/
int check_pair(t_pair *pair, char *input)
{
    int i;
    int return_false;

    (i = -1, return_false = 0);
    while (pair[++i].ob)
    {
        if (redundant_rule(pair[i]) && ++return_false)
            err_msg_4(input, SUB_ERR_3, pair[i].ob->index);

        else if (ob_left_rule(pair[i].ob->prev) && ++return_false)
            err_msg_4(input, SUB_ERR_2, pair[i].ob->index);

        else if (cb_left_rule(pair[i].cb->prev) && ++return_false)
            err_msg_4(input, SUB_ERR_2, pair[i].cb->index);

        else if (cb_right_rule(pair[i].cb->next) && ++return_false)
            err_msg_4(input, SUB_ERR_1, pair[i].cb->next->index);

        if (return_false)
            return (FALSE);
    }
    return (TRUE);
}

int redundant_rule(t_pair pair)
{
    return (pair.ob->prev && pair.cb->next
            && pair.ob->prev->type == OB
            && pair.cb->next->type == CB);
}

int ob_left_rule(t_token *ob_left)
{
  return (ob_left 
        && ob_left->type != AND
        && ob_left->type != OR
        && ob_left->type != PIPE
        && ob_left->type != OB);
}

int cb_left_rule(t_token *cb_left)
{
  return (cb_left->type == OB);
}

int cb_right_rule(t_token *cb_right)
{
  return (cb_right 
        && (cb_right->type == OB
        || cb_right->type == STR));
}