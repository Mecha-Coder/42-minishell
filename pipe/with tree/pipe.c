#include "header.h"

int run_pipe(t_tree *node)
{
    int fd[2];
    pid_t child1;
    pid_t child2;
    int status;

    pipe(fd);
    node->left->pipe = fd;
    node->right->pipe = fd;

    child1 = fork();
    if (child1 == 0) 
    {
        if (node->left->type == CMD)
        {
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
        }
        descent_tree(node->left);
    }
  

    child2 = fork();
    if (child2 == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        if (node->pipe)
        {
            close(node->pipe[0]);
            dup2(node->pipe[1], STDOUT_FILENO);
        }
        descent_tree(node->right);
    }
   
    close(fd[0]);
    close(fd[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
   
    return(WEXITSTATUS(status));
}