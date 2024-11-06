#include "header.h"

int descent_tree(t_tree *node)
{
    int status;

    if (node->type == CMD)
        status = run_cmd(node);
    else if (node->type == PIPE)
        status = run_pipe(node);
    if (node->pipe)
        exit(status);
    return (status);
}