#include "../include/minishell.h"

int ft_clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return (EXIT_SUCCESS);
}