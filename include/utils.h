/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:37 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 15:00:37 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_empty(char *s);
int		word_count(char *s);
void	free_list(char **list);
int		is_identifier(char *s, int *i);
int		find_word(char *s, char *word);
int		detection(char c, int *state, int sub);
char	*join3(char *s1, char *s2, char *s3);

// Error message
void	err_msg_1(char *builtin, char *arg, char *msg);
void	err_msg_2(char *builtin, char *arg, char *msg);
void	err_msg_3(char *builtin, char *msg);
void	err_msg_4(char *input, char *msg, int index);
void	err_msg_5(char *delimiter);
void	err_exit(char *action, int code);
int		arg_count(char **args, char *builtin);

#endif