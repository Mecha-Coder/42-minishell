/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:24:05 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 14:24:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void destroy_token(t_token *token)
{
    t_token *temp;
    
    while (token)
    {
        free(token->content);
        temp = token->next;
        free(token);
        token = temp;
    }
}
