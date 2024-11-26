/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:23 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:05:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> sub_quote
Purpose: 
- Subtitute quotes with non-printable
- To differentiate quotes that are operator with string quotes 
(help with expansion) 
==============================================================================
Method

quote 1 and 3 --> ASCII(30) = "
quote 2 and 4 --> ASCII(26) = '

Refer util/detection for what 1,2,3,4 mean
==============================================================================
Param
- char *s  : input string
- int sub  : 
    TRUE : sub quote  non-printable
    FALSE: Reverse sub
*/

void sub_quote(char *s, int sub)
{
    int i;
    int detect;
    int quote;

    (i = -1, detect = ON);
    while (s[++i])
    {
        quote = detection(s[i], &detect, !sub);
        if (sub && (quote == 1 || quote == 3))
            s[i] = (char)30;
        else if (sub && (quote == 2 || quote == 4))
            s[i] = (char)26;
        else if (!sub && (quote == 1 || quote == 3))
            s[i] = '\"';
        else if (!sub && (quote == 2 || quote == 4))
            s[i] = '\'';
    }
}

/* Test 
void print_none(char *s)
{
    int i = -1;

    while(s[++i])
    {
        if (s[i] == 26)
            printf("(");
        else if (s[i] == 30)
            printf(")");
        else
            printf("%c", s[i]);
    }
    printf("\n");
}

int main()
{
    char s1[] = "This 'is'";
    char s2[] = "\"Awesome\"";
    char s3[] = "\"It's\" a fantastic day to \"'skate'\"";
    char s4[] = "'$USER' \"USER\"";
    sub_quote(s1, TRUE);
    sub_quote(s2, TRUE);
    sub_quote(s3, TRUE);
    sub_quote(s4, TRUE);
    
    print_none(s1);
    print_none(s2);
    print_none(s3);
    print_none(s4);
    
    sub_quote(s1, FALSE);
    sub_quote(s2, FALSE);
    sub_quote(s3, FALSE);
    sub_quote(s4, FALSE);
    
    printf("\n");
    print_none(s1);
    print_none(s2);
    print_none(s3);
    print_none(s4);
}
*/