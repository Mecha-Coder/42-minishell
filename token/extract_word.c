/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:14:27 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 22:14:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> extract_word
Purpose:
- Take processed input after extract_token
- Split word by "space" delimiter and create token
==============================================================
Example
-           |    ON      |    OFF      | ON 
    Input:  Month   of   "November 2024"\0
          0011111000110001111111111111110
-           ^    ^  ^ ^  ^              ^
-           S    C  S C  S              C               
==============================================================
Return 
- token *operator
- NULL, if not found any operator
*/

t_token *extract_word(char *s)
{
    int is_word;
    
    while (s && *s)
    {
        detection
        if (delimiter)
        {
            if (is_word)

            is_word = FALSE;
        }
        else
            is_word = TRUE;
    }
}

int delimiter(char c)
{
    return(c == ' ' || c == '\0');
}