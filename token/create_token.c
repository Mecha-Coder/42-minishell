/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:21:01 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 10:21:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *create_token(void)
{
    t_token *new;

    new = (t_token *)malloc(sizeof(t_token));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    ft_memset(new, 0, sizeof(t_token));
    return (new);
}