/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:58:00 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:58:00 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

// Input
int	check_bracket(char *s);
int	check_occurance(char *s);
int	check_quote(char *s);

// Token
int	check_combine(t_shell *data);
int	check_redirect(t_shell *data);
int	check_subshell(t_shell *data);
int	check_pair(t_pair *pair, char *input);

#endif