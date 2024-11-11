#include "../../include/minishell.h"

int  scan_bracket(t_tree *node)
{
    int i;
    int bracket;
    
    (i = token_len(node->token), bracket = 0);
    while (--i > -1)
    {
        if (node->token[i].type == CB)
        {
            bracket++;
            if (bracket == 1)
                node->token[i].type = 0;
        }
        else if (node->token[i].type == OB)
            bracket--;
        if (!bracket && node->token[i].type == OB)
        {
            node->token[i].type = 0;

            node->type = SUB;
            node->left = create_node();
            if (node->left)
                node->left->token = &node->token[i + 1];
            return (TRUE);
        }
    }
    return (FALSE);
}