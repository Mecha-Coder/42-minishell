/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:39:25 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 08:39:25 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return (EXIT_SUCCESS);
}
