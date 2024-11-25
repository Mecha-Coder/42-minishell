/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_wild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:23 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:05:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> sub_wild
Purpose: 
- Subtitute (*) outside quote with non-printable character.
- WHY! To differentiate asterisk inside quote with wildcard 
==============================================================================
Method

-"d*m"* = d*m[w]
- d*m*  = d[w]m[w]

Sub with ASCII(31)
==============================================================================
Param
- char *s  : input string
- int sub 
    TRUE : Sub (*) outside quote with ASCII(31)
    FALSE: Reverse sub ASCII(31) with (*)
*/

void sub_wild(char *s, int sub)
{
    int i;
    int detect;

    (i = -1, detect = ON);
    while (sub && s[++i])
    {
        detection(s[i], &detect);
        if (detect == ON && s[i] == '*')
            s[i] = (char)31;
    }
    while (!sub && s[++i])
    {
        if (s[i] == (char)31)
            s[i] = '*';
    }
}

/* Test

int main()
{
    char s1[] = "\"d*m\"*";
    char s2[] = "\"*Awesome*\"";
    char s3[] = "*Awesome*";
    char s4[] = "\"It's*\" a fantastic * day to *";
    sub_wild(s1, TRUE);
    sub_wild(s2, TRUE);
    sub_wild(s3, TRUE);
    sub_wild(s4, TRUE);
    printf("%s\n%s\n%s\n%s", s1, s2, s3, s4);
    sub_wild(s1, FALSE);
    sub_wild(s2, FALSE);
    sub_wild(s3, FALSE);
    sub_wild(s4, FALSE);
    printf("\n\n%s\n%s\n%s\n%s\n", s1, s2, s3, s4);
}
*/
