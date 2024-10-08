#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

# define PROMPT "\001\e[0m\e[33m\002Minishell> \001\e[0m\002"

void buildin(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{   
    char *input;

    while (1)
    {
        input = readline(PROMPT);
        if (input)
        {
            if (!strcmp("clear", input))
                buildin();
            else if (!strcmp("exit", input))
            {
                free(input);
                break;
            }
            else if (input[0])
                printf("%s\n",input);
            free(input);
        }
    }
    return (0);
}