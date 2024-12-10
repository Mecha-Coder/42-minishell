/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:22:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/04 09:51:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> expansion
Purpose: 
- Receive token and expand variable $_ and wildcard *
- Handle expansion for word and redirect differently
- Removing all quotes 
=============================================================================
Example
- Input  : "This is $USER's pc named $1$?$h *"
- Output :  This is jpaul's pc named 0 file1 file2 file3
=============================================================================
Return
	TRUE  : All expanded successully 
	FALSE : Failed @ ambiguous redirect
			(Expansion for redirect can fail if match != 1)
=============================================================================
Side effect
- The expansion may cause 1st token element to be deleted
- address of data->token is invalid. 
- So reassign data->token = token_jumpback(current)

Note: type = HERE won't get expanded (skip)
*/
int	expansion(t_tree *node, t_shell *data)
{
	t_token	*current;

	current = node->token;
	while (current)
	{
		sub_quote(current->content, TRUE);
		if (current->type >= 5 && current->type <= 7
			&& !expand_redir(current, data))
		{
			return (FALSE);
		}
		else if (current->type == STR)
			current = expand_str(current, data);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	node->token = token_jumpback(current);
	return (TRUE);
}

/* Test
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void answer(char *s, char **env)
{
	t_shell data;
	int status;

	setup_env(&data, env);
	data.cmd_exit_no = 47;

	append_env("a", "hi       there      $SHELL      *", data.env);
	append_env("h", "o  a\"b\"c", data.env);
	append_env("q", "*   \"*\"  *   *", data.env);
	append_env("key1", "d'm*", data.env);
	append_env("key2", "hello there", data.env);

	data.input = s;

	tokenize(&data);
	merge_redirect(data.token);
	printf("Before\n");
	show_token(data.token, 'C');
	status = expansion(&data);
	printf("After\n");
	show_token(data.token, 'C');

	if (status)
		printf(GREEN "OK\n" RESET);
	else
		printf(RED "ERROR\n" RESET);

	destroy_token(data.token);
	destroy_env(&data);

	printf("\n\n-------------------------------\n");
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	answer("$USER", env);
	answer("$", env);
	answer("\"$USER\"", env);
	answer("$HOME$", env);
	answer("$PATH", env);
	answer("$SHELL", env);
	answer("$~", env);
	answer("\"$\"", env);
	answer("\"$aa\"", env);
	answer("$SHELL$HOME", env);
	answer("'\"$USER\"'  \"'$USER'\"", env);
	answer("\"[Path $SHELL  ' $SHELL ' && XX]\"", env);
	answer("'$USER'", env);
	answer("Hi \"there$USER next\"", env);
	answer("Hi \"there$USERnext\"", env);
	answer("Hi \"there$USER$?next\"", env);
	answer("there$USER$!loo", env);
	answer("there$USER$HANTUloo", env);
	answer(" Hi \"there$USER$^next\"", env);
	answer("\"[Path $SHELL  '  ' && !]\"", env);
	answer("\"[Path $SHELL$]\"", env);
	answer("\"[Test \'still\' valid $USER]\"", env);
	answer("\"Path: /usr/local/bin\"", env);
	answer("\"It's a beautiful day\"", env);
	answer("\"Exit status: $?\"", env);
	answer("\"a\"s\"f\"g\"h\"", env);
	answer("'[Path $SHELL "  " && !]'", env);
	answer(" '$USER'", env);
	answer("'Hello       World'", env);
	answer("$USER", env);
	answer("'Exit status: $?'", env);
	answer("'a's'f'f'g'h", env);
	answer("\"This 'is'\"", env);
	answer("\"Awesome\"", env);
	answer("\"It's\" a fantastic day to \"'skate'\"", env);
	answer("\"Exit is $\"? ", env);
	answer("User$USER@42kl", env);
	answer("$12345", env);
	answer("$$!lo$a:User", env);
	answer("##$500", env);
	answer("Try expand '$USER'", env);
	answer("$USER$!lo$SWAP_VAR:User$abc", env);
	answer("$?Exit is $?$?### and $?'|'$? $?", env);
	answer("\"I'm\"", env);
	answer("'a's'f'f'g'h", env);
	answer("\"a\"s\"f\"g\"h\"", env);
	answer("Path \"$SHELL  '  ' && !\"", env);
	answer("'A'B'\"C'\"\"", env);
	answer("'$username \"USER\"'", env);
	answer("'a's'f'f'g'h", env);
	answer("\"a\"s\"f\"g\"h\"", env);
	answer("'A'B\"'C'\"", env);
	answer("*", env);
	answer("**", env);
	answer("*log", env);
	answer("*txt", env);
	answer("du*log", env);
	answer("tex*", env);
	answer("*um*", env);
	answer("du*m*t", env);
	answer("*du*m", env);
	answer("*dsad*", env);
	answer("'d*'*", env);
	answer("> file*", env);
	answer("> *logx", env);
	answer("> *ex*", env); 
	answer("> *tt*", env);
	answer("> *none*", env);
	answer("< d*m*", env);
	answer("<<HERE << * > *", env);
	answer(">> dm", env);
	answer(">> dm.txt", env);
	answer("$USER\"$USER#right\"'$USER'", env);
	answer("$$!lo\"$a\":User", env);
	answer("$$!lo'$a':User", env);
	answer("$Something'$Done:'", env);
	answer("$hh", env);
	answer("ec$a\"a\"", env);
	answer("'Hello*'*", env);
	answer("\"d*m\"*", env);
	answer("\"*Awesome*\"", env);
	answer("*Awesome*", env);
	answer("\"It's*\" a fantastic * day to *", env);
	answer("\"I'm\"", env);
	answer("'a's'f'f'g'h", env);
	answer("\"a\"s\"f\"g\"h\"", env);
	answer("Path \"$SHELL  '  ' && !\"", env);
	answer("'A'B'\"C'\"\"", env);
	answer("'$username \"USER\"'", env);
	answer("'Exit status: $?'", env);
	answer("'a's'f'f'g'h", env);
	answer("\"a\"s\"f\"g\"h\"", env);
	answer("'A'B\"'C'\"", env);
	answer("$qwe << EOF", env);
	answer("echo *", env);
	answer("e'c'ho a\"b\"c", env);
	answer("echo \"dumm\"*", env);
	answer("echo \"dumm*\"", env);
	answer("$d $h d*m", env);
	answer("ec$a", env);
	answer("ec\"$a\" > file/out 'Nice       day' >> file/ou1 $h", env);
	answer("$h ec\"$a\" > file/out 'Nice       day' >> file/ou1", env);
	answer("ec'$a'", env);
	answer("###$a#Hello$?", env);
	answer("\"###$a#Hello\"", env);
	answer("$a", env);
	answer("\"$a\"", env);
	answer("e'c'h$h", env);
	answer("e'c'h\"$h\"", env);
	answer("echo hel\"$a\"", env);
	answer("echo hel$a", env);
	answer("$key2", env);
	answer("hello.txt$sosej", env);
	answer("*logx", env);
	answer("filename", env);
	answer("*um*2*", env);
	answer("<< EOF > *alogx", env);
	answer("t\"*\"t", env);
	answer("dum$key1", env);
	answer("$key3", env);
	answer("$someting", env);
	answer("< \"$aa\"", env);
	answer("< $aa", env);
	answer("export \"$aa\"", env);
	answer("export $aa", env);
	answer("export $0 ~$!~ ~$@~", env);
}
*/
