#include "header.h"

int none_builtin(t_tree *x)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        execve(x->path, x->cmd, x->env);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
        waitpid(child, &status, 0);
    return (WEXITSTATUS(status));
}
int ft_printf(t_tree *x)
{
    int i = -1;

    while (x->cmd[++i])
        printf("%s\n", x->cmd[i]);
    return (EXIT_SUCCESS);
}

int run_cmd(t_tree *node)
{
    int status;

    if (!strcmp(node->cmd[0], "print"))
        status = ft_printf(node);
    else
        status = none_builtin(node);
    return (status);
}