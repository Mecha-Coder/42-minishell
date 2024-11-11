#include "../../include/minishell.h"

int descent_tree(t_tree *node, t_shell *data)
{
    int status;

    if (node->type == CMD)   status = run_cmd(node, data);
    if (node->type == PIPE)  status = run_pipe(node, data);
    if (node->type == SUB)   status = run_subshell(node, data);
    if (node->type == AND)   status = run_and(node, data);
    if (node->type == OR)    status = run_or(node, data);
    if (node->terminate)
        exit(status);
    return (status);
}

void run_ast(t_shell *data)
{
    data->cmd_exit_no = descent_tree(data->tree, data);
}