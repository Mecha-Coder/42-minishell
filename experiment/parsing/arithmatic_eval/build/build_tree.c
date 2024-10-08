#include "../eval.h"

int isempty(char *s)
{
    while (*s)
    {
        if (!isspace(*s++))
            return (FALSE);
    }
    return (TRUE);
}

void build_tree(t_node *node)
{
    if (!node->s || isempty(node->s))
        return;
    
    if (scan_plus_minus(node) 
        || scan_multiply_divide(node))
    {
        build_tree(node->left);
        build_tree(node->right);
    }
    else if (scan_bracket(node)) 
        build_tree(node);
    else if (!scan_number(node)) 
    {
        printf("Invalid math expression\n");
        exit(EXIT_FAILURE);
    }
}
/*
int main()
{
    char *s;

    s = "";
    printf("\n[%s] -> %d\n", s, isempty(s));
    s = "   ";
    printf("\n[%s] -> %d\n", s, isempty(s));
    s = "\n \n \t";
    printf("\n[%s] -> %d\n", s, isempty(s));
    s = "hello";
    printf("\n[%s] -> %d\n", s, isempty(s));
    s = "   a";
    printf("\n[%s] -> %d\n", s, isempty(s));
    s = "\n \n nice to meet you\t";
    printf("\n[%s] -> %d\n", s, isempty(s));
}
*/