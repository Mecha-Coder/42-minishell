/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:52:50 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:52:50 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

int		run_here(t_tree *node, t_shell *data);
int		do_redirect(t_token *current);
void	manage_io(int *fd, int action);

#endif