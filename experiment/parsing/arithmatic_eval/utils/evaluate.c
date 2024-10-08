#include "../eval.h"

int evaluate(t_node *node)
{
    if(!node)
        return (0);
    if (node->type)
    {
        if (node->type == '+')
            return (evaluate(node->left) + evaluate(node->right));
        if (node->type == '-')
            return (evaluate(node->left) - evaluate(node->right));
        if (node->type == '*')
            return (evaluate(node->left) * evaluate(node->right));
        if (node->type == '/')
            return (evaluate(node->left) / evaluate(node->right));
    }
    return (node->val);
}