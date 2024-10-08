#include "../eval.h"

void print_indent_level(int i)
{
    while (i > 1 && i--)
        printf("      ");
    if (i)
        printf("|_____");
}

void visualize_tree(t_node *node, int level)
{
    if (!node)
        return;

    if (!node->s)
        (printf("Tree error: Str is null\n"), exit(1));
    if (node->type < 0)
        (printf("Tree error: Type is blank\n"), exit(1));
    if (node->type && (!node->left || !node->right))
        (printf("Tree error: operator must have left & right\n"), exit(1));
    if (!node->type && (node->left || node->right))
        (printf("Tree error: number shouldn't have left or right\n"), exit(1));

    print_indent_level(level);
    if (node->type)
    {
        printf("%c\n", node->type);
        level++;
        visualize_tree(node->left, level);
        visualize_tree(node->right, level);
    }
    else
        printf("%d\n",node->val); 
}

/*
int main()
{
    t_node *n1, *n2, *n3, *n4, *n5;

    n1 = create_node();
    n2 = create_node();
    n3 = create_node();
    n4 = create_node();
    n5 = create_node();

    n1->s = "(2 + 3) * 4";
    n1->type = '*';
    n1->left = n2;
    n1->right = n3;

    n2->s = "2 + 3";
    n2->type = '+';
    n2->left = n4;
    n2->right = n5;

    n3->s = " 4";
    n3->type = NUMBER;
    n3->val = 4;

    n4->s = "2 ";
    n4->type = NUMBER;
    n4->val = 2;

    n5->s = " 3";
    n5->type = NUMBER;
    n5->val = 3;

    visualize_tree(n1, 0);
    destroy_tree(n1);
    return (0);
}
*/