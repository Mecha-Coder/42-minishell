/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:54:14 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:54:14 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	sigint_handler(int signo);
void	sigquit_handler(int signo);
void	sigint_handler_child(int signo);
void	sigquit_handler_child(int signo);
void	heredoc_handler(int signo);
int		get_status(int status);

#endif
