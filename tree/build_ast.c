/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:25:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 22:25:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
- Scan token from right to left
Precedence
*/
void build_ast(t_shell *data)
{
    data->tree = create_tree(data->token);
    branchout_tree(data->tree);
}

void branchout_tree(t_tree *node)
{
    t_token *current;

    if (!node)
        return ;
    current = node->token;
    while ()
    
}