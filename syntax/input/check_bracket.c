/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bracket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:01:35 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 21:01:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> check_bracket
Purpose: Bracket must be in pair O_BRACKET followed by C_BRACKET
====================================================================
Method

O_BRACKET, track++
C_BRACKET, track--

track < 0, meaning CB comes before OB
track > 0, meaning OB and CB not even pairs
track = 0, all brackets are paired
====================================================================
Return
  TRUE  : All bracket have pair
  FALSE : vice versa
*/
int check_bracket(char *s)
{
    int i;
    int detect;
    int track;
    int index;

    (i = -1, detect = ON, track = 0);
    while (track >= 0 && s && s[++i])
    {
        detection(s[i], &detect);
        if (detect == ON && s[i] == '(')
        {
            track++;
            index = i;
        }
        else if (detect == ON && s[i] == ')')
            track--;
    }
    if (!track)
        return (TRUE);
    if (track > 0)
        err_msg_syntax(s, "invalid bracket placement", index);
    else
        err_msg_syntax(s, "invalid bracket placement", i);
    return(FALSE);
}

/*
void answer(char *s)
{
    if (check_bracket(s))
        printf("%s\nOK\n", s);
    printf("\n\n------------------\n");
}

int main()
{
    answer(") ) echo hello ( ( || cat");
    answer("echo hello ( \")\"");
    answer("echo ((");
    answer("( echo hello ) && (( echo hi  )  ");
    answer("(echo hello");
    answer("(echo hello))");

    answer("(echo hello)");
    answer("echo hello && (echo nice && ls) && echo hi");
    answer("((echo hello))");
    answer("(echo hi) (echo hello)");
    answer("hello");
}
*/
