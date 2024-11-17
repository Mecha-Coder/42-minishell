#include "../../include/minishell.h"

int descent_tree(t_tree *node, t_shell *data)
{
    int status;

    if (node->type == CMD)
        status = run_cmd(node, data);
    if (node->type == PIPE)
        status = run_pipe(node, data);
    if (node->pipe)
        exit(status);
    return (status);
}

void run_ast(t_shell *data)
{
    
    signal(SIGINT, sigint_handler_child);
    signal(SIGQUIT, sigquit_handler_child);
    data->cmd_exit_no = descent_tree(data->tree, data);
}