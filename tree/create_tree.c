/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:10:51 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 22:10:51 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_tree *create_tree(t_token *token)
{
    t_tree *new;

    new = (t_tree *)malloc(sizeof(t_tree));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    ft_memset(new, 0, sizeof(t_tree));
    new->token = token;
    return (new);
}