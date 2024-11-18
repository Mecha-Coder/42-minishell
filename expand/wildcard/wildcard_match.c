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
Return: 
    TRUE : Match wildcard pattern
    FALSE: Not matching wildcard pattern
*/
int wildcard_match(char *entry, char *pattern)
{
    if (*pattern == '\0')
        return (*entry == '\0');
    if (*pattern == '*')
        return (wildcard_match(entry, pattern + 1) 
            || (*entry && wildcard_match(entry + 1, pattern)));
    if (*pattern == *entry)
        return (wildcard_match(entry + 1, pattern + 1));
    return FALSE;
}