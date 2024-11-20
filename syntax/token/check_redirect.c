/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:48:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/20 12:31:03 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> check_redirect
Purpose: Check redirect token must be followed by word token<STR>
===================================================================
Example
    <WR><STR> OK
    <RD><AND> KO
====================================================================
Return
  TRUE  : All redirect token have word token after that
  FALSE : vice versa
*/

int check_redirect(t_shell *data)
{
    t_token *current;

    current = data->token;
    while (current)
    {
        if (current->type >= 4 && current->type <= 7
            && current->next->type != STR)
        {
            err_msg_syntax(data->input, "after redirect must be a word"
                , current->next->index);
            return (FALSE);
        }
    }
    return (TRUE);
}

int answer(char *s)
{
    t_shell data;

    data.input = s;

    
}

int main()
{
    char s1[] = "cat < in.txt && ls"
}

