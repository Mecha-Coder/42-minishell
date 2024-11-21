/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _token_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:41:34 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 11:45:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> token_array
Purpose: 
- To evaluate subshell brackets, my technique require editing the token info.
- token_array is a quick way to duplicate master token with mininum info
*/
t_sub *token_array(t_token *current)
{
    t_sub *new;
    int i;

    i = 0;
    while (current && ++i && current->next)
        current = current->next;
    new = (t_sub *)malloc(sizeof(t_sub) * (i + 1));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    current = token_jumpback(current);
    i = 0;
    while (current)
    {
        new[i++] = (t_sub){current->type, current->index};
        current = current->next;
    }
    new[i] = (t_sub){0, -1};
    return (new);
}