#include "../eval.h"

void branch(t_node *node, int i)
{
    node->type = node->s[i];
    node->s[i] = '\0';

    node->left = create_node();
    node->right = create_node();

    node->left->s = &node->s[0];
    node->right->s = &node->s[i + 1];
}

/*
int main()
{
    t_node *root;
    char s[] = "This is awesome";

    root = create_node();
    root->s = s;
    branch(root, 5);

    printf("%s\n", root->left->s);
    printf("%s\n", root->right->s);
}
*/
