/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:24:05 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 11:08:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void destroy_token(t_token *token)
{
    t_token *temp;
    
    while (token)
    {
        if (token->content)
            free(token->content);
        if (token->herefd[0] > 2 && token->herefd[1] > 2)
        {
            close(token->herefd[0]);
            close(token->herefd[1]);
        }
        temp = token->next;
        free(token);
        token = temp;
    }
}
