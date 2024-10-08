#include "../eval.h"

void detail_node(t_node *node)
{
    if (!node)
        return;

    printf("\n");
    printf("%p\n", node);
    printf("String: \"%s\"\n", node->s);
    printf("Type  : [%c]\n"  , node->type);
    printf("Value : %d\n"    , node->val);
    printf("Left  : %p\n"    ,node->left);
    printf("Right : %p\n"    ,node->right);
    printf("\n-----------------------------------\n");
    detail_node(node->left);
    detail_node(node->right);
}