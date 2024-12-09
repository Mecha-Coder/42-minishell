/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:39:22 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 13:59:38 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> join3
Purpose: Take 3 string input and join them together
Note: This function can handle NULL or blank input string
====================================================================
Return 
- char : joined string (malloc)
       : if all 3 input are NULL it will return ("\0")
*/

char *join3(char *s1, char *s2, char *s3)
{
    int i;
    int total;
    char *new;
    
    i = 0;
    total = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
    new = (char *)malloc(total + 1);
    if (!new)
        err_exit("malloc", errno);
    while (s1 && *s1)
        new[i++] = *s1++;
    while (s2 && *s2)
        new[i++] = *s2++;
    while (s3 && *s3)
        new[i++] = *s3++;
    new[i] = '\0';
    return (new);
}

/* Test 
int main()
{
    char *str;

    str = join3("Today","is","Saturday");
    printf("[%s]\n", str);
    free(str);

    str = join3("Nice", NULL, "\0");
    printf("[%s]\n", str);
    free(str);

    str = join3(NULL, NULL, NULL);
    printf("[%s]\n", str);
    free(str);

    str = join3("Tomo", "rrow", NULL);
    printf("[%s]\n", str);
    free(str);

    str = join3("\0", "124", "@gmail");
    printf("[%s]\n", str);
    free(str);
}
*/