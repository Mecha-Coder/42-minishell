#include "../../include/minishell.h"

int run_subshell(t_tree *node, t_shell *data)
{
    int status;
    pid_t id;

    node->left->terminate = TRUE;
    id = fork();
    if (id == 0)
        descent_tree(node->left, data);
    waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}