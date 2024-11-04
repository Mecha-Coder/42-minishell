#include "../include/minishell.h"



int run_cmd(t_tree *node, t_shell *data)
{
    // pid_t id;
    // int status;
    
    if (polish_str_token(node->token, data))
    {
        prep_cmd(node);

        // if      (!ft_strcmp(node->cmd[0], "cd"))     ft_cd(node->cmd, data);
        // else if (!ft_strcmp(node->cmd[0], "pwd"))    ft_pwd();
        // else if (!ft_strcmp(node->cmd[0], "env"))    ft_env();
        // else if (!ft_strcmp(node->cmd[0], "exit"))   ft_exit();
        // else if (!ft_strcmp(node->cmd[0], "echo"))   ft_echo();
        if      (!ft_strcmp(node->cmd[0], "export")) ft_export(node->cmd, data->env);
        else if (!ft_strcmp(node->cmd[0], "unset"))  ft_unset(node->cmd, data);

        // id = fork();
        // if (id < 0) return (perror("fork failed"), EXIT_FAILURE);
        // else if (!id)
        // {
        //     prep_pipe(node);
        //     none_builtin(node->cmd, data->env);
        // }
        // else
        //     waitpid(id, &status, 0);
        // return (WEXITSTATUS(status));
    }
    return (EXIT_SUCCESS);
}
