#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#define CYELLOW "\001\e[0;31m\002"
#define RESET   "\001\e[0m\002"

void reset_prompt() 
{
    write(1, "\n", 1);
    rl_on_new_line();// Inform Readline that we are on a new line
}

void print_str(char *s)
{
    while (s && *s)
        write(1, s++, 1);
}

int main() 
{
    char *input;

    rl_on_new_line();
    while ((input = readline(CYELLOW "prompt> " RESET)) != NULL)
    {
        if (*input)
        {
            add_history(input);
            print_str(input);
            free(input); 
            reset_prompt();
        }   
    }

    return 0;
}