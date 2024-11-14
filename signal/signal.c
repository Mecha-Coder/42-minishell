/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:23 by jetan             #+#    #+#             */
/*   Updated: 2024/11/14 18:10:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_signal = 0;

void	sigint_handler(int signo)
{
	(void)signo;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigquit_handler(int signo)
{
	(void)signo;
	printf("Quit\n");
}

void	sigint_handler_child(int signo)
{
	(void)signo;
	printf("\n");
}

void	sigquit_handler_child(int signo)
{
	(void)signo;
	printf("Quit\n");
}