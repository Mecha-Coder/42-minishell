/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:55:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 10:58:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int space_char(char c);

/* >>>is_empty
Purpose: Check if input string 
- is empty input[0] = '\0' or 
- space character   "     "
=======================================================
Return  :
    OK  : TRUE
    KO  : FALSE
*/
int is_empty(char *s)
{
	while (s && *s)
	{
		if (!space_char(*s++))
			return (FALSE);
	}
	return(TRUE);
}

static int space_char(char c)
{
    return (c == ' ' || c == '\t');
}