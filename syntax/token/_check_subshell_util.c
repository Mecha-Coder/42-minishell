/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_subshell_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:14:12 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 14:24:16 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_pair *create_pair(t_token *ob, t_pair *prev)
{
    t_pair *new;

    new = (t_pair *)malloc(sizeof(t_pair));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    new->ob = ob;
    if (prev)
        prev->next = new;
    new->prev = prev;
    new->new = NULL;
    new->cb = NULL;
    return (new);
}

void destroy_pair(t_pair *current)
{
    t_pair *temp;

    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
}

t_pair *pair_jumpforward(t_pair *current)
{
    while (current && current->next)
        current = current->next;
    return (current);
}