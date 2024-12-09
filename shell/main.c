/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:23:18 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 19:39:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int g_sig = 0;

int main(int ac, char **av, char **env)
{
    t_shell data;

    (void)ac;
    (void)av;
    initialize(&data, env);
    prompt(&data);
    ft_putstr_fd("exit\n", 2);
    close_shell(data.cmd_exit_no, &data);
}