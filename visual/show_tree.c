/* 
- This is for visual only
- remove after done with project 
*/

#include "../include/minishell.h"

static void print_indent(int i)
{
    while (i > 1 && i--)
        printf("      ");
    if (i)
        printf("|_____");
}

void show_tree(t_tree *node, int level)
{
    if (!node)
        return ;
    print_indent(level);
    print_type_2(node->type); printf(": ");
    show_token(node->token, 'C');
    level++;
    show_tree(node->left, level);
    show_tree(node->right, level);
}