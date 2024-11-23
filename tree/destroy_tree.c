/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:30:38 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/23 10:34:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void destroy_tree(t_tree *node)
{
    if (!node)
        return ;
    if (node->token)
        destroy_token(node->token);
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
}