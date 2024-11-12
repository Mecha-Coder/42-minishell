#include "header.h"

void prompt_heredoc(t_tree *node)
{
    if (!node)
        return;

    while (node->in && node->in->type)
    {
        if (node->in->type = HERE)

    }
    prompt_heredoc(node->left);
    prompt_heredoc(node->right);
}

int main()
{
    t_token t1[] = {
        {STR, "echo", 0, 0},
        {STR, "Hello", 0, 0},
        {0, NULL, 0, 0} 
    };
    
    t_token t2[] = {
        {STR, "echo", 0, 0},
        {STR, "Hi", 0, 0},
        {0, NULL, 0, 0} 
    };

    t_token t3[] = {
        {STR, "cat", 0, 0},
        {0, NULL, 0, 0} 
    };

    t_token t4[] = {
        {HERE, "DONE", 0, 0},
        {0, NULL, 0, 0}
    };

    t_tree n5 = {CMD, t2, NULL, NULL, NULL, NULL, NULL, 0};
    t_tree n4 = {CMD, t1, NULL, NULL, NULL, NULL, NULL, 0};
    t_tree n3 = {CMD, t3, t4, NULL, NULL, NULL, NULL, 0};
    t_tree n2 = {AND, NULL, NULL, NULL, &n4, &n5, NULL, 0};
    t_tree n1 = {AND, NULL, NULL, NULL, &n2, &n3, NULL, 0};

    visualize_tree(&n1, 0);

    prompt_heredoc(&n1);

}