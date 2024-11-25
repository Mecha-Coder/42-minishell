
#include "../../include/minishell.h"

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