/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:07:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:27:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >> del_quote
Purpose: 
- Receive type of quote to remove
- Remove it from string (don't remove opposite quote wrap inside)
=============================================================================
Example
    
remove: "double-quote"
    
given string:  This pc is named "'0'"
                        ↓ <-- copy all char to temp except those to be remove 
malloc temp :  This pc is named '0'
                        ↓
        <copy back to string and free temp>
=============================================================================
Param
- char *s : input string
- int type
    1 : S_QUOTE
    2 : D_QUOTE                        
*/

void del_quote(char *s, int type)
{
    int i;
    int j;
    int num;
    int detect;
    char *temp;

    (i = -1, j = 0, detect = ON);
    temp = (char *)malloc(ft_strlen(s) + 1);
    if (!temp)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    while (s && s[++i])
    {
        num = detection(s[i], &detect);
        if (type == D_QUOTE && num != 1 && num != 3)
            temp[j++] = s[i];
        if (type == S_QUOTE && num != 2 && num != 4)
            temp[j++] = s[i];
    }
    temp[j] = '\0';
    ft_strcpy(s, temp);
    free(temp);
}

/* Test

void answer(char *s, int type)
{
    printf("Input : %s\n", s);
    del_quote(s, type);
    printf("Output: %s\n"
           "-------------------------\n\n", s);
}


int main()
{
    int type;

    char s1[] = "\"I'm\"";
    char s2[] = "'a's'f'f'g'h";
    char s3[] = "\"a\"s\"f\"g\"h\"";
    char s4[] = "Path \"$SHELL  '  ' && !\"";
    char s5[] = "'A'B'\"C'\"\"";

    char s6[] = "'$username \"USER\"'";
    char s7[] = "'Exit status: $?'";
    char s8[] = "'a's'f'f'g'h";
    char s9[] = "\"a\"s\"f\"g\"h\"";
    char s10[] = "'A'B\"'C'\"";

    printf("Remove double quote"
           "\n====================\n\n");
    type = D_QUOTE;
    answer(s1, type);
    answer(s2, type);
    answer(s3, type);
    answer(s4, type);
    answer(s5, type);

     printf("Remove single quote"
           "\n====================\n\n");
    type = S_QUOTE;
    answer(s6, type);
    answer(s8, type);
    answer(s9, type);
    answer(s7, type);
    answer(s10, type);
}
*/