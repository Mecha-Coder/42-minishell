#include "../eval.h"

int  scan_plus_minus(t_node *node)
{
    int i, bracket;

    bracket = 0;
    i = strlen(node->s) - 1;

    while (i > -1)
    {
        if (node->s[i] == ')')
            bracket++;
        else if (node->s[i] == '(')
            bracket--;
        else if (!bracket 
            && (node->s[i] == '+' || node->s[i] == '-'))
        {
            branch(node ,i);
            return (TRUE);
        }
        i--;
    }
    return (FALSE);
}

/*
void show_result(char *s)
{
    t_node *root;
    
    root = create_node();
    root->s = s;
    if (scan_plus_minus(root))
    {
        printf("-type: %d\n", root->type);
        printf("-left: \"%s\"\n", root->left->s);
        printf("-right: \"%s\"\n", root->right->s);
    }
    else
        printf("\nNot found\n");
    printf("-------------------------\n\n");
}

int main()
{
    char s1[] = "5 + 6 * 3";
    show_result(s1);

    char s2[] = "((5 - 6) + (3 + 6))";
    show_result(s2);

    char s3[] = "34 - (63 + (3 + 6))";
    show_result(s3);

    char s4[] = "456 + 324 + 44";
    show_result(s4);
    
    return (0);
}
*/

