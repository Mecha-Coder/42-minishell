/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:13:36 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/27 11:18:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> word_count
Purpose: 
- Is used for determine the number of words in a string
- Set to detect quote after sub to non-printable
- Delimited by " " space and \0
*/
int word_count(char *s)
{
    int i;
    int detect;
    int flag;
    int count;

    (i = -1, detect = ON, count = 0, flag = FALSE);
    while (s[++i])
    {
        detection(s[i], &detect, TRUE);
        if (detect == ON && (s[i] == ' ' || s[i] == '\0'))
            flag = FALSE;
        else
        {
            if (!flag)
                count++;
            flag = TRUE;
        }
    }
    return (count);
}

/* Test
void answer(char *s)
{ 
    printf("%s\n", s);
    sub_quote(s, TRUE);
    printf("count: %d\n", word_count(s));
    printf("\n----------------------------\n");

}

int main()
{
    char s1[] = "   Today   is   \"a rainy day\"";
    char s2[] = "'Nice data'";
    char s3[] = "Count these words now";
    char s4[] = "'Wonderful day' splendid work \"Trick or treat\" Nice";
    char s5[] = "";
    printf("\n");
    answer(s1);
    answer(s2);
    answer(s3);
    answer(s4);
    answer(s5);
}
*/

  

