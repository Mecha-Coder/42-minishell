/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:43:29 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 13:48:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> exit_2str
Purpose: Convert exit_code (int) into string

IMPORTANT: Require char buffer of (3) from parent
======================================================================
Param
char *s : reference char pointer from parent
          MUST BE BUFFER 3
int code: exit code 
          MUST RANGE FROM 0 - 999       
*/

void exit_2_str(char *s, int code)
{
    int i;
    char temp;

    if (s && code < 0)
        return;
    i = 0;
    s[0] = '0';
    s[1] = '\0';
    s[2] = '\0';
    while (code && i < 3)
    {
        s[i++] = (code % 10) + '0';
        code = code / 10;
    }
    i = ft_strlen(s);
    if (i > 1)
    {
        temp = s[0];
        s[0] = s[i - 1];
        s[i - 1] = temp; 
    }
}

/* Test

int main()
{
    char str[3];
    
    exit_2_str(str, 0);
    printf("%s\n", str);
    exit_2_str(str, 1);
    printf("%s\n", str);
    exit_2_str(str, 2);
    printf("%s\n", str);
    exit_2_str(str, 9);
    printf("%s\n", str);
    exit_2_str(str, 15);
    printf("%s\n", str);
    exit_2_str(str, 65);
    printf("%s\n", str);
    exit_2_str(str, 100);
    printf("%s\n", str);
    exit_2_str(str, 255);
    printf("%s\n", str);
    exit_2_str(str, 998);
    printf("%s\n", str);
}
*/