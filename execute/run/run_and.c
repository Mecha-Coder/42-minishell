#include "../../include/minishell.h"

int run_and(t_tree *node, t_shell *data)
{
    int status;

    status = descent_tree(node->left, data);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
    }
    if (!status && !descent_tree(node->right, data))
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}