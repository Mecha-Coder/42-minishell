/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:22:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/17 15:33:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> exp_var
Purpose
- Remove quotes
- Scan for variable ($_ _ _) in string 
- Then swap/insert it coresponding value
=============================================================================
Example
- Input  : "This is $USER's pc named '$1$?$h'"
- Output :  This is jpaul's pc named '0'
=============================================================================
Return
- char : expanded string (malloc)
=============================================================================
Side effect
- The 1st param (char *s) is malloc
- exp_var will help to free it.
*/

char *exp_var(char *s, t_shell *data)
{
    char *new;

    sub_squote(s, TRUE);
    del_quote(s, D_QUOTE);
    s = insert_var(s, data);
    del_quote(s, S_QUOTE);
    sub_squote(s, FALSE);
    return (s);
}
