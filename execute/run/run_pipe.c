#include "../../include/minishell.h"

void child_left(int *fd, t_tree *node, t_shell *data)
{
    node->left->pipe = fd;
    if (node->left->type == CMD)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
    }
    descent_tree(node->left, data);
}

void child_right(int *fd, t_tree *node, t_shell *data)
{
    node->right->pipe = fd;
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
    }
    descent_tree(node->left, data);
}

int run_pipe(t_tree *node, t_shell *data)
{
    int fd[2];
    int status;
    pid_t child1;
    pid_t child2;

    if (pipe(fd) < 0) 
        return (perror("pipe failed"), EXIT_FAILURE);
    
    child1 = fork();
    if (child1 == 0)
        child_left(fd, node, data);
    else
    {
        waitpid(child1, &status, 0);
        close(fd[1]);
    }

    child2 = fork();
    if (child2 == 0)
        child_right(fd, node, data);
    else
    {
        waitpid(child2, &status, 0);
        close(fd[0]);
    }

    if (node->pipe)    
        exit(WEXITSTATUS(status));
    return (WEXITSTATUS(status));
}