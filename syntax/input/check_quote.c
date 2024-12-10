/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 17:03:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >> check_quote
Purpose: Check single (') and double (") quotes must be in pair
=====================================================================
Method
		  ON  |   DQ_OFF    |
  Input: echo "This is var's"
			  ^             ^
		 00000100000000000003

detect = 1 or 2, track++
detect = 3 or 4, track--
- if all quote have pair track should be zero,
====================================================================
Return
  TRUE  : All quotes have pair
  FALSE : vice versa
*/

int	check_quote(char *s)
{
	int	i;
	int	j;
	int	detect;
	int	track;
	int	index;

	i = -1;
	detect = ON;
	track = 0;
	while (s && s[++i])
	{
		j = detection(s[i], &detect, FALSE);
		if (j > 0)
		{
			if (j > 2)
				track--;
			else
				track++;
			index = i;
		}
	}
	if (!track)
		return (TRUE);
	err_msg_4(s, "quote not in pair", index);
	return (FALSE);
}

/*
void answer(char *s)
{
	if (check_quote(s))
		printf("%s\nOK\n", s);
	printf("\n\n------------------\n");
}

int main()
{
	answer("echo \"Double' quote: '");
	answer("echo \"Done'\" '");
	answer("echo 'Single quote: \''");
	answer("echo 'Done\"' \"");
	answer("'l''s");
	answer("try '\"this\"");
	answer("echo a's'f'f'g'h");
	answer("echo \"a\"sf\"g\"h\"");

	answer("echo \"[Path $SHELL  '  ' && !]\"");
	answer("echo \"[Path $SHELL$]\"");
	answer("echo \"[Test \'still\' valid $USER]\"");
	answer("echo \"Path: /usr/local/bin\"");
	answer("echo \"It's a beautiful day\"");
	answer("echo \"Exit status: $?\"");
	answer("echo \"a\"s\"f\"g\"h\"");
	answer("echo '[Path $SHELL \"  \" && !]'");
	answer("echo '$USER'");
	answer("echo '$USER'");
	answer("echo 'Hello World'");
	answer("echo 'Exit status: $?'");
	answer("echo 'a's'f'f'g'h");
	answer("hello");
}
*/