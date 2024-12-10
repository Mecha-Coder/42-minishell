/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:49:22 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:49:22 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

// Step
void	del_quote(char *s);
void	sub_quote(char *s, int sub);
void	sub_wild(char *s, int sub);
int		expand_redir(t_token *token, t_shell *data);
int		expansion(t_tree *node, t_shell *data);
t_token	*expand_str(t_token *current, t_shell *data);

// Variable
void	exit_2_str(char *s, int code);
char	*insert_var(char *s, t_shell *data);
char	*insert_exit(char *s, int *i, int code);
char	*insert_value(char *s, int *i, int len, t_env *env);

// Wildcard
int		wild_match(char *entry, char *pattern);
int		wild_redir(char **match, char *pattern);
t_token	*wild_str(char *pattern);

#endif