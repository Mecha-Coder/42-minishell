/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_wild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:23 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:05:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> sub_wild
Purpose: 
- Subtitute (*) outside quote with non-printable character.
- WHY! To differentiate asterisk inside quote with wildcard 
==============================================================================
Method

-"d*m"* = d*m[w]
- d*m*  = d[w]m[w]

Sub with ASCII(31)
==============================================================================
Param
- char *s  : input string
- int sub 
	TRUE : Sub (*) outside quote with ASCII(31)
	FALSE: Reverse sub ASCII(31) with (*)
*/

void	sub_wild(char *s, int sub)
{
	int	i;
	int	detect;

	i = -1;
	detect = ON;
	while (sub && s[++i])
	{
		detection(s[i], &detect, TRUE);
		if (detect == ON && s[i] == '*')
			s[i] = (char)31;
	}
	while (!sub && s[++i])
	{
		if (s[i] == (char)31)
			s[i] = '*';
	}
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
	printf("Sub quote   : ");
	print_none(s);

	sub_wild(s, TRUE);
	printf("Sub wildcard: ");
	print_none(s);

	del_quote(s);
	printf("Del quote   : ");
	print_none(s);

	sub_wild(s, FALSE);
	printf("Rev sub wild: %s\n", s);
	printf("\n-------------------------\n\n");
}

int main()
{
	char s1[] = "\"d*m\"*";
	char s2[] = "\"*Awesome*\"";
	char s3[] = "*Awesome*";
	char s4[] = "\"It's*\" a fantastic * day to *";
	
	answer(s1);
	answer(s2);
	answer(s3);
	answer(s4);
}
 */
