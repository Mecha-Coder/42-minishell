/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:28:59 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/03 12:51:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> exp_wild
Purpose: 
- Match wildcard pattern against files/folders in the current dir.
- Loop each entry, if match -> create a <STR> token.
- Return all accumulated tokens after checking all files/folders

NOTE: Only <STR> token. Wildcard for redirect do @ redirect stage
===========================================================================
Example

Current dir    Pattern: du*m*
==========
dummy.txt <MATCH>
dm.txt 
dump.log  <MATCH>
text.jpg
===========================================================================
Return
- No match   : NULL
- Found match: accumulated token (linked-list head)
				 <STR >  ⇋   <STR>
			   dummy.txt    dump.log
*/

t_token	*wild_str(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	t_token			*current;

	current = NULL;
	dir = opendir(".");
	if (!dir)
		err_exit("opendir", errno);
	entry = readdir(dir);
	while (entry)
	{
		if (wild_match(entry->d_name, pattern))
			current = create_token(STR, ft_strdup(entry->d_name),
					0, current);
		entry = readdir(dir);
	}
	closedir(dir);
	return (sort_token(current, 'C'));
}

/* Test
void answer(char *pattern)
{
	printf("\npattern: %s\n\n", pattern);

	sub_quote(pattern, TRUE);
	sub_wild(pattern, TRUE);
	del_quote(pattern);

	t_token *token = wild_str(pattern);
	t_token *current = token;
	if (!current)
	{
		printf("Match not found\n");
		printf("\n------------------------\n");
		return;
	}
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	destroy_token(token);
	printf("\n------------------------\n");
}


int main()
{
	char s1[] = "*";
	char s2[] = "**";
	char s3[] = "*log";
	char s4[] = "*txt";
	char s5[] = "du*log";
	char s6[] = "tex*";
	char s7[] = "*um*";
	char s8[] = "du*m*t";
	char s9[] = "*du*m";
	char s10[] = "*dsad*";
	char s11[] = "'d*'*";

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
	answer(s11);

	// Font dot
	.*   // Both . ..
	.***  // Both . ..
	
	// Middle
	.*.     // ..
	 .***.  // ..

	// Back
	**.  // None
	*.   // None
	
	char s12[] = ".*";
	char s13[] = ".***";
	char s14[] = ".*.";
	char s15[] = ".***.";
	char s16[] = "**.";
	char s17[] = "*.";
	answer(s12);
	answer(s13);
	answer(s14);
	answer(s15);
	answer(s16);
	answer(s17);
}
*/