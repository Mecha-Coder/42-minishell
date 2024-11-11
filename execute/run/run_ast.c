#include "../../include/minishell.h"

int run_subshell(t_tree *node, t_shell *data)
{
    int status;
    pid_t id;

    id = fork();
    if (id == 0)
        descent_tree(node->left, data);
    waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}

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

int run_or(t_tree *node, t_shell *data)
{
    int status;

    status = descent_tree(node->left, data);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
    }
    if (!status || !descent_tree(node->right, data))
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int descent_tree(t_tree *node, t_shell *data)
{
    int status;

    if (node->type == CMD)   status = run_cmd(node, data);
    if (node->type == PIPE)  status = run_pipe(node, data);
    if (node->type == SUB)   status = run_subshell(node, data);
    if (node->type == AND)   status = run_and(node, data);
    if (node->type == OR)    status = run_or(node, data);
    if (node->pipe)
        exit(status);
    return (status);
}

void run_ast(t_shell *data)
{
    data->cmd_exit_no = descent_tree(data->tree, data);
}