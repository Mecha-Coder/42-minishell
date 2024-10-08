#include "../eval.h"

int  scan_bracket(t_node *node)
{
    int i, bracket;
    
    bracket = 0;
    i = strlen(node->s) - 1;

    while (i > -1)
    {
        if (node->s[i] == ')')
        {
            bracket++;
            if (bracket == 1)
                node->s[i] = '\0';
        }
        else if (node->s[i] == '(')
            bracket--;
        if (!bracket && node->s[i] == '(' )
        {
            node->s = &node->s[i + 1];
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
    if (scan_bracket(root))
   {
        printf("-type: %s\n", root->s);
        printf("-left: \"%p\"\n", root->left);
        printf("-right: \"%p\"\n", root->right);
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

    char s3[] = "(63 + (3 + 6))";
    show_result(s3);

    char s4[] = "(324 * 44)";
    show_result(s4);

    char s5[] = "(324 * 44)";
    show_result(s5);

    char s6[] = "(5 - 6) + (3 + 6)";
    show_result(s6);

    char s7[] = "63 + (8 + 9)";
    show_result(s7);
    
    return (0);
}
*/

