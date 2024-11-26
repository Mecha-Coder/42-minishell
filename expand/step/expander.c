/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:22:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/17 15:33:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> exp_var
Purpose
- Remove quotes
- Scan for variable ($_ _ _) in string 
- Then swap/insert it coresponding value
=============================================================================
Example
- Input  : "This is $USER's pc named '$1$?$h'"
- Output :  This is jpaul's pc named '0'
=============================================================================
Return
- char : expanded string (malloc)
=============================================================================
Side effect
- The 1st param (char *s) is malloc
- exp_var will help to free it.
*/

char *exp_var(char *s, t_shell *data)
{
    sub_squote(s, TRUE);
    del_quote(s, D_QUOTE);
    s = insert_var(s, data);
    del_quote(s, S_QUOTE);
    sub_squote(s, FALSE);
    return (s);
}


/* >>> exp_wild
Purpose: 
- Match wildcard pattern against files/folders in the current dir.
- Loop: For each match, create a <STR> token.
- Free token that has the pattern
- Relinking master token with the new accumulated token

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
Return: NONE



Return
- No match   : NULL
- Found match: accumulated token (linked-list head)
                 <STR >  ⇋   <STR>
               dummy.txt    dump.log
*/

//- Return all accumulated tokens after checking all files/folders




void expander(t_token *current, t_shell *data)
{
    int count;
    t_token *collection;

    while (current)
    {
        if (current->type != HERE)
        {
            current->content = expand_var(current->content, data);
            count = var_word_count(current->content);
            if (current->type >= 4 && current->type <= 7 && count != 1)
                return // Ambious baba
            if (current->type == STR && !count)
                remove_token(current);
            else (count > 1) 
                collection = split_var(current->content);
            else


        }
    }



    sub_squote(s, TRUE);
    del_quote(s, D_QUOTE);
    s = insert_var(s, data);
    del_quote(s, S_QUOTE);
    sub_squote(s, FALSE);
    return (s);
}

/* Test 

void answer(char *s, t_shell *data)
{
    char *input = (char *)malloc(ft_strlen(s) + 1);
    ft_strcpy(input, s);

    printf("Input  : [%s]\n", input);
    char *output = exp_var(input, data);
    printf("\nOutput : [%s]\n", output);
    printf("\n------------------------\n\n");
    free(output);
}

int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    setup_env(&data, env);
    data.cmd_exit_no = 47;

    answer("$USER", &data);
    answer("$", &data);
    answer("\"$USER\"", &data);
    answer("$HOME$", &data);
    answer("$PATH", &data);
    answer("$SHELL", &data);
    answer("$~", &data);
    answer("\"$\"", &data);
    answer("\"$aa\"", &data);
    answer("$SHELL$HOME", &data);
    answer("'\"$USER\"'  \"'$USER'\"", &data);
    answer("\"[Path $SHELL  ' $SHELL ' && XX]\"", &data);
    answer("'$USER'", &data);
    answer("Hi \"there$USER next\"", &data);
    answer("Hi \"there$USERnext\"", &data);
    answer("Hi \"there$USER$?next\"", &data);
    answer("there$USER$!loo", &data);
    answer("there$USER$HANTUloo", &data);
    answer(" Hi \"there$USER$^next\"", &data);
    answer("\"[Path $SHELL  '  ' && !]\"", &data);
    answer("\"[Path $SHELL$]\"", &data);
    answer("\"[Test \'still\' valid $USER]\"", &data);
    answer("\"Path: /usr/local/bin\"", &data);
    answer("\"It's a beautiful day\"", &data);
    answer("\"Exit status: $?\"", &data);
    answer("\"a\"s\"f\"g\"h\"", &data);
    answer("'[Path $SHELL "  " && !]'", &data);
    answer(" '$USER'", &data);
    answer("'Hello World'", &data);
    answer("$USER", &data);
    answer("'Exit status: $?'", &data);
    answer("'a's'f'f'g'h", &data);
    answer("\"This 'is'\"", &data);
    answer("\"Awesome\"", &data);
    answer("\"It's\" a fantastic day to \"'skate'\"", &data);
    answer("\"Exit is $\"? ", &data);
    answer("User$USER@42kl", &data);
    answer("$12345", &data);
    answer("$$!lo$a:User", &data);
    answer("##$500", &data);
    answer("Try expand '$USER'", &data);
    answer("$USER$!lo$SWAP_VAR:User$abc", &data);
    answer("$?Exit is $?$?### and $?|$? $?", &data);
    answer("\"I'm\"", &data);
    answer("'a's'f'f'g'h", &data);
    answer("\"a\"s\"f\"g\"h\"", &data);
    answer("Path \"$SHELL  '  ' && !\"", &data);
    answer("'A'B'\"C'\"\"", &data);
    answer("'$username \"USER\"'", &data);
    answer("'a's'f'f'g'h", &data);
    answer("\"a\"s\"f\"g\"h\"", &data);
    answer("'A'B\"'C'\"", &data);

    destroy_env(&data);
} 
*/