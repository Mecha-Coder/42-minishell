/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:47:35 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/17 13:03:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *insert_exit(char *s, int *i, int code)
{
    char buffer[3];
    char *result;
    
    s[*i] = '\0';
    exit_2_str(buffer, code);
    result = join3(s, buffer, &s[*i + 2]);
    *i += ft_strlen(buffer);
    return (result);    
}

/* Test

// ***** CAUTION: Checking  if "$?" need to be done at latest str ***** 
int main()
{
    int i = 0;
    char sample[] = "$?Exit is $?$?### and $?|$? $?";
    char *s;
    char *temp;

    // ***** SOLUTION: free s at this stage ******
   
    s = (char *)malloc(ft_strlen(sample) + 1);
    ft_strcpy(s, sample);

    printf("\n%s\n", s);
    temp = NULL;
    while (s[i])
    {
        if (s[i] == '$' && s[i + 1] == '?')
        {
            temp = insert_exit(s, &i, 55);
            free(s);
            s = temp;
            printf("%s\n", s);
        }
        else
            i++;
    }
    free (s);
}
*/