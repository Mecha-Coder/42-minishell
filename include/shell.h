/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:53:54 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:53:54 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

int		input_syntax(t_shell *data);
int		token_syntax(t_shell *data);
void	prompt(t_shell *data);
void	initialize(t_shell *data, char **env);
void	close_shell(int code, t_shell *data);

#endif