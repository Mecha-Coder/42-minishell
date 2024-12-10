/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:39:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/10 21:39:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
-    ↓
echo "EE
Syntax error: quote not in pair
*/
void	err_msg_4(char *input, char *msg, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		ft_putstr_fd(" ", 2);
	ft_putstr_fd("↓\n", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd("\nminishell: syntax error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

/*
For handling malloc, pipe, fork error
Exit program.
*/
void	err_exit(char *action, int code)
{
	err_msg_3(action, strerror(code));
	exit(EXIT_FAILURE);
}

/*
Here doc error message
minishell: warning: here-document delimited by end-of-file (wanted `%s')
*/
void	err_msg_5(char *delimiter)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: ", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}
