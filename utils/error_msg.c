/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:02:40 by jetan             #+#    #+#             */
/*   Updated: 2024/11/04 15:56:08 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// minishell: cd: `Helllo': Invalid path
void	err_msg_1(char *builtin, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

// minishell: cd: Hello: Invalid path
void	err_msg_2(char *builtin, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

// minishell: cd: HOME not set
void	err_msg_3(char *builtin, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

/*
-    ↓
echo "EE
Syntax error: quote not in pair
*/
void err_msg_4(char *input, char *msg, int index)
{
	int i;

	i = 0;
	while(i++ < index)
		ft_putstr_fd(" ", 2);
	ft_putstr_fd("↓\n", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd("\n\033[1m\033[31mSyntax error: \033[0m", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

/*
For handling malloc, pipe, fork error
Exit program.
*/
void err_exit(char *action, int code)
{
	err_msg_3(action, strerror(code));
	exit(EXIT_FAILURE);
}

/*
Here doc error message
minishell: warning: here-document delimited by end-of-file (wanted `%s')
*/
void err_msg_5(char *delimiter)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: ", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}


// Message to JOHN: Revert to me if in doubt
int	arg_count(char **args, char *builtin)
{
	int		count;
	
	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		err_msg_3(builtin, "too many arguments");
		return(FALSE);
	}
	return (TRUE);
}
