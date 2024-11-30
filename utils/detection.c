/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:38:04 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/17 15:09:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void initialize_detection(char *s_quote, char *d_quote, int sub);

/* >>> detection
Purpose:
- To be used by parent function

Task1: track/update state to let parent know
- ON           : can detect meta
- SQ or DQ OFF : don't detect meta

Task2: Return integer
- 0    : Character read is not a quote
- > 0  : What type of quote detected, and whether it's the start or end
=============================================================================
Param:
- char c     : The current reading character by the parent
- int *state : reference pointer to &state from parent function
- int sub    : is quote sub wil non-printable
    TRUE : non-printable
	FALSE: Normal      
=============================================================================
Example

state: ON  |  DQ_OFF   |  ON
           "Hello there"
           ^           ^
return     1000000000003 
=============================================================================
Slight modification for expansion

Issue 
- after expanding to its value quote will be remove 
- But want to retain quotes inside the quote
- Similarly asterisk inside quote is not a wildcard which will change 
  the search pattern 

"'Hello"  |  " "a" "  | ' This "" is '  |  "start*"*

Solution: In expansion stage will substitute these symbol with non-printable

' --> ASCII(26)
" --> ASCII(30)
* --> ASCII(31)

=============================================================================
Return:
- 0 : Character read not a quote
- 1 : Read double quote, detection OFF
- 2 : Read single quote, detection OFF
- 3 : Read double quote, detection ON
- 4 : Read single quote, detection ON
=============================================================================
Side effect
- Update the state pointer at child so parent can use it
 * ON (0)
 * SQ_OFF (1)
 * DQ_OFF (2)
*/

int detection(char c, int *state, int sub)
{
	char s_quote;
	char d_quote;

	initialize_detection(&s_quote, &d_quote, sub);
    if (c == d_quote && *state == ON)      {*state = DQ_OFF; return (1);}
	if (c == s_quote && *state == ON)      {*state = SQ_OFF; return (2);}
	if (c == d_quote && *state == DQ_OFF)  {*state = ON;return (3);}
	if (c == s_quote && *state == SQ_OFF)  {*state = ON;return (4);}
	return (0);
}

static void initialize_detection(char *s_quote, char *d_quote, int sub)
{
	if (sub)
	{
		*s_quote = (char)26;
		*d_quote = (char)30;
	}
	else
	{
		*s_quote = '\'';
		*d_quote = '\"';
	}
}

/*
int main()
{
	int i = -1;
	int detect = ON;
	char s[] = "'\"$USER\"'  \"'USER'\"";
	
	printf("%s\n", s);

	while (s[++i])
		printf("%d", detection(s[i], &detect, FALSE));
	printf("\n\n\n");

	s[0] = 26;
	s[8] = 26;
	s[11] = 30;
	s[18] = 30;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 26)
			printf("(");
		else if (s[i] == 30)
			printf(")");
		else
			printf("%c", s[i]);
	}
	printf("\n");

	i = -1;
	while (s[++i])
		printf("%d", detection(s[i], &detect, TRUE));
	printf("\n\n");
}
*/
