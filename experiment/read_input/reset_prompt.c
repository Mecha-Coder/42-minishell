#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void reset_prompt() 
{
    write(1, "\n", 1);
    rl_on_new_line();// Inform Readline that we are on a new line
	//rl_replace_line("", 0);  // Replace the current line with new_text
	//rl_redisplay();// Redisplay the updated line
}

void print_str(char *s)
{
    while (s && *s)
        write(1, s++, 1);
}

int main() 
{
    char *input;

    while ((input = readline("Enter text: ")) != NULL)
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