/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:11:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 15:51:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_token	*join_token(t_token *t1, t_token *t2);

/* >>> tokenize
Purpose: Create a token representation of the input
==================================================================
Example
	Input     :  cat  < in.txt  &&  ls
	Token list: <STR><RD><STR><AND><STR>
	Type      :   10   5   10   1   10
==================================================================
Method
Input :  cat <in.txt && ls
		 123456789012345678

Stage1: Extract operator and replace with space character

	Input      : cat___in.txt____ls
	Token list: <RD><AND>
	Index     :  5   14

Stage2: Extract word with space as delimiter

	Content   :           cat in.txt ls     
	Token list: <RD><AND><STR><STR><STR>
	Index     :  5   14    1    7    17

Stage3: Sort index
==================================================================
Caution
- Output for these 2 can be NULL
	operator = extract_operator(s);
	word = extract_word(s);
Make sure join_token can handle NULL token 
==================================================================
Param 
- t_shell data
*/
void	tokenize(t_shell *data)
{
	char	*s;
	t_token	*operator;
	t_token	*word;

	s = ft_strdup(data->input);
	operator = extract_operator(s);
	word = extract_word(s, FALSE);
	data->token = join_token(operator, word);
	free(s);
}

// Note: Either one can be null but not both
static t_token	*join_token(t_token *t1, t_token *t2)
{
	t1 = token_jumpfront(t1);
	if (t1)
		t1->next = t2;
	if (t2)
		t2->prev = t1;
	if (t1)
		return (sort_token(t1, 'I'));
	return (sort_token(t2, 'I'));
}

/* Test 
void answer(char *s)
{
	t_shell data;

	data.input = s;
	tokenize(&data);
	show_token(data.token, 'V');
	printf("-------------------\n");
	destroy_token(data.token);
}

int main()
{
	char s1[] = "(echo hI && echo done) | tr a-z A-Z | wc -l";
	char s2[] = "echo hello";
	char s3[] = "";
	char s4[] = "(echo \"World\" && (echo \"Hello\"))";
	char s5[] = "grep \"pattern\" file.txt || echo \"Not found\"";
	char s6[] = "> out1.txt echo \">>>>> out.txt\" < in.txt";

	answer(s1);
	answer(s2);
	answer(s3);
	answer(s4);
	answer(s5);
	answer(s6);
}
*/
