/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:21:01 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 12:47:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_token *create_token_node(void)
{
    t_token *new;

    new = (t_token *)malloc(sizeof(t_token));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    return (new);
}

t_token *create_token(int type, char *content, int index, t_token *prev_token)
{
    t_token *new;
    
    new = create_token_node();
    new->type = type;
    new->content = content;
    new->index = index;
    new->next = NULL;
    new->prev = prev_token;
    if (prev_token)
        prev_token->next = new;
    new->herefd[0] = 0;
    new->herefd[1] = 0;
    return (new);
}