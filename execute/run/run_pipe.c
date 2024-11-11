#include "../../include/minishell.h"

static void left(int *fd, t_tree *node, t_shell *data);
static void right(int *fd, t_tree *node, t_shell *data);

int run_pipe(t_tree *node, t_shell *data)
{
    int fd[2];
    int status;
    pid_t id_1;
    pid_t id_2;

    if (pipe(fd) < 0) 
        return (perror("pipe failed"), EXIT_FAILURE);
    node->left->pipe = fd;
    node->left->terminate = TRUE;
    node->right->terminate = TRUE;

    id_1 = fork();
    if (!id_1)
        left(fd, node, data);

    id_2 = fork();
    if (!id_2)
        right(fd, node, data);

    close(fd[0]);
    close(fd[1]);
    waitpid(id_1, &status, 0);
    waitpid(id_2, &status, 0);
    return (WEXITSTATUS(status));
}

static void left(int *fd, t_tree *node, t_shell *data)
{
    if (node->left->type == CMD ||
        node->left->type == SUB)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
    }
    descent_tree(node->left, data);
}

static void right(int *fd, t_tree *node, t_shell *data)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
    }
    descent_tree(node->right, data);
}