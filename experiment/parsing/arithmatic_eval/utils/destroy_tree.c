#include "../eval.h"

void destroy_tree(t_node *node)
{
    if (!node)
        return ;
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
    node = NULL;
}