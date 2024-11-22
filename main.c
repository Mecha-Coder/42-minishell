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
        if (check_input_syntax(&data))
        {
            tokenize(&data);
            if (check_token_syntax(&data))
            {
                printf("%s\n" GREEN "OK\n" RESET,data.input);
                destroy_token(data.token);
            }
        }    
    }
    destroy_env(&data);
}



