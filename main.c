#include "include/minishell.h"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main(int ac, char **av, char **env)
{
    t_shell data;
    initialize(&data, env);

    if (ac == 2 && !is_empty(av[1]))
    {
        data.input = av[1];
        if (!check_input_syntax(&data))
            return (destroy_env(&data), 0);
        tokenize(&data);
        if (!check_token_syntax(&data))
            return (destroy_env(&data), 0);
        build_ast(&data);
        printf("\n%s\n\n",data.input);
        show_tree(data.tree, 0);
        printf("\n");
        destroy_tree(data.tree);
    }
    destroy_env(&data);
}



