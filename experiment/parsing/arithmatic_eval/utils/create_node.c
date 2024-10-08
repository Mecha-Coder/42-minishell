#include "../eval.h"

t_node *create_node(void)
{
    t_node *new;

    new = (t_node *)malloc(sizeof(t_node));
    if (new)
    {
        new->s = NULL;
        new->type = -1;
        new->val = 0;
        new->left = NULL;
        new->right = NULL;
    }
    return (new);
}
