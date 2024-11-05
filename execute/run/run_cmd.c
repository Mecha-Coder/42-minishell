#include "../../include/minishell.h"

int run_cmd(t_tree *node, t_shell *data)
{
    int status;
    
    status = EXIT_FAILURE;
    if (polish_str_token(node->token, data))
    {
        prep_cmd(node);

        if      (!ft_strcmp(node->cmd[0], "pwd"))    status = ft_pwd();
        else if (!ft_strcmp(node->cmd[0], "clear"))  status = ft_clear();
        else if (!ft_strcmp(node->cmd[0], "echo"))   status = ft_echo(node->cmd);
        else if (!ft_strcmp(node->cmd[0], "export")) status = ft_export(node->cmd, data);
        else if (!ft_strcmp(node->cmd[0], "unset"))  status = ft_unset(node->cmd, data);
        else if (!ft_strcmp(node->cmd[0], "cd"))     status = ft_cd(node->cmd, data);
        else if (!ft_strcmp(node->cmd[0], "env"))    status = ft_env(node->cmd, data);
        else if (!ft_strcmp(node->cmd[0], "exit"))   status = ft_exit(node->cmd, data);
        else                                         status = none_builtin(node->cmd, data->env);
    }
    if (node->pipe)
        exit(status);
    return (status);
}
