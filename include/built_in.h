/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:42:58 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:42:58 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

int	ft_pwd(void);
int	ft_echo(char **args);
int	ft_export(char **args, t_shell *env);
int	ft_unset(char **args, t_shell *data);
int	ft_cd(char **args, t_shell *data);
int	ft_env(char **args, t_shell *data);
int	ft_exit(char **args, t_shell *data);

#endif