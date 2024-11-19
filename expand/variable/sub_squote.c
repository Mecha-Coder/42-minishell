/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_squote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:23 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:05:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> sub_squote
Purpose: 
- Subtitute (') quote inside "double quote" temporarily.
- WHY! In expanding stage all quote will be removed
- Except quote enclosed with the opposite qoute  <---- !IMPORTANT
==============================================================================
Example
"I'm"              : I'm
'$username "USER"' : username "jpaul" 
'A'B'"C'""         : AB"C
==============================================================================
Var Expansion stage

1st : Remove "double qoute".
      Now, easier to check if $_ _ _  inside 'single quote' ignore 

2nd : Find $_ _ _ and expand accordingly
3rd : Remove 'single quote'   <---- !PROBLEM

In the 3rd stage, those (') inside "double quote" has no protection
and will get deleted. But we want to retain it. To solve this, add:

stage 0  : Sub (') inside "double quote" with dummy character ASCII(26)
stage 4th: Reverse sub ASCII(26) to (')
==============================================================================
Param
- char *s  : input string
- int sub  : 
    TRUE : Do stage 0
    FALSE: Do stage 4 
*/

void sub_squote(char *s, int sub)
{
    int i;
    int detect;

    (i = -1, detect = ON);
    while (sub && s[++i])
    {
        detection(s[i], &detect);
        if (detect == DQ_OFF && s[i] == '\'')
            s[i] = (char)26;
    }
    while (!sub && s[++i])
    {
        if (s[i] == (char)26)
            s[i] = '\'';
    }
}

/* Test

int main()
{
    char s1[] = "This 'is'";
    char s2[] = "\"Awesome\"";
    char s3[] = "\"It's\" a fantastic day to \"'skate'\"";
    sub_squote(s1, TRUE);
    sub_squote(s2, TRUE);
    sub_squote(s3, TRUE);
    printf("%s\n%s\n%s", s1, s2, s3);
    sub_squote(s1, FALSE);
    sub_squote(s2, FALSE);
    sub_squote(s3, FALSE);
    printf("\n\n%s\n%s\n%s\n", s1, s2, s3);
}
*/