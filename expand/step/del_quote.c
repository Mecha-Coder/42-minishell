/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:07:48 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:10:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >> del_quote
Purpose: Remove quote operator from string (not quote in string)
=============================================================================
Example
	
given string:  This pc is named "'0'"
						↓ <-- copy all char to temp except those to be remove 
malloc temp :  This pc is named '0'
						↓
		<copy back to string and free temp>                 
*/

void	del_quote(char *s)
{
	int		i;
	int		j;
	int		detect;
	char	*temp;

	i = -1;
	j = 0;
	detect = ON;
	temp = (char *)malloc(ft_strlen(s) + 1);
	if (!temp)
		err_exit("malloc", errno);
	while (s && s[++i])
	{
		if (!detection(s[i], &detect, TRUE))
			temp[j++] = s[i];
	}
	temp[j] = '\0';
	ft_strcpy(s, temp);
	free(temp);
}

/* Test 
void print_none(char *s)
{
	int i = -1;

	while(s[++i])
	{
		if (s[i] == 26)
			printf("(");
		else if (s[i] == 30)
			printf(")");
		 else if (s[i] == 31)
			printf("^");
		else
			printf("%c", s[i]);
	}
	printf("\n");
}

void answer(char *s)
{
	printf("Input       : %s\n", s);
	
	sub_quote(s, TRUE);
	printf("Sub to none : ");
	print_none(s);

	del_quote(s);
	printf("Remove quote: ");
	print_none(s);
	printf("\n-------------------------\n\n");
}


int main()
{
	char s1[] = "\"I'm\"";
	char s2[] = "'a's'f'f'g'h";
	char s3[] = "\"a\"s\"f\"g\"h\"";
	char s4[] = "Path \"$SHELL  '  ' && !\"";
	char s5[] = "'A'B'\"C'\"\"";

	char s6[] = "'$username \"USER\"'";
	char s7[] = "'Exit status: $?'";
	char s8[] = "'a's'f'f'g'h";
	char s9[] = "\"a\"s\"f\"g\"h\"";
	char s10[] = "'A'B\"'C'\"";

	printf("\n");
	answer(s1);
	answer(s2);
	answer(s3);
	answer(s4);
	answer(s5);
	answer(s6);
	answer(s7);
	answer(s8);
	answer(s9);
	answer(s10);
}
*/
