/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:14 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 14:59:14 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>>wildcard_match
Purpose: Determine if entry text meet wildcard pattern
===============================================================
Example:
pattern: h*lo;  
  
   hello (TRUE)  mello (FALSE)
===============================================================
Issue:
- In linux can create filename: "d*m.txt"
- There's difference between d*m* and "d*m"* 
- "*" symbol inside quote is not a wildcard  

Example we have filename: d'mmy.txt
  
-"d*m"* = d*m[w]   ---> Not a match
- d*m*  = d[w]m[w] ---> Match

[w] - wildcard

Solution: 
- Before analysing swap wildcard with ASCII(31)
- This help to differentiate "*" and [w]
===============================================================
Return: 
    TRUE : Match wildcard pattern
    FALSE: Not matching wildcard pattern
*/
int wild_match(char *entry, char *pattern)
{
    if (*pattern == '\0')
        return (*entry == '\0');
    if (*pattern == (char)31)
        return (wild_match(entry, pattern + 1) 
            || (*entry && wild_match(entry + 1, pattern)));
    if (*pattern == *entry)
        return (wild_match(entry + 1, pattern + 1));
    return FALSE;
}
/*
void answer(char *pattern)
{
    if (wildcard_match("d'mmy.txt", pattern))
        printf("Match\n");
    else
        printf("Not match\n");
}

int main()
{        //      0123 
    char s[] = "d*m*";
    s[3] = (char)31;
    answer(s);
    s[1] = (char)31;
    answer(s);
}
*/