#include "include/minishell.h"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main(int ac, char **av, char **env)
{
    t_shell data;
    initialize(&data, env);

    if (ac == 2 && !is_empty(av[1]))
    {
        data.input = ft_strdup(av[1]);
        if (input_syntax(&data))
        {
            tokenize(&data);
            if (token_syntax(&data))
            {
                build_ast(&data);
                run_heredoc(data.tree);
                run_ast(&data);
                free(data.input);
                destroy_tree(data.tree);
            }
        }
    }
    destroy_env(&data);
    exit(data.cmd_exit_no);
}



