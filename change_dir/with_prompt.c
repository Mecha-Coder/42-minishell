#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#define COLOR "\033[33m"
#define RESET "\033[0m"
// gcc with_prompt.c -lreadline

char *prompt(char *s)
{
    char dir[PATH_MAX];
    
    memset(s, 0 , sizeof(prompt));
    strcat(s, COLOR);
    strcat(s, getcwd(dir, sizeof(dir)));
    strcat(s, " >> ");
    strcat(s, RESET);
    return (s);
}

int main()
{   
    char *input;
    char s[PATH_MAX + sizeof(">> ")];

    while (1)
    {
        input = readline(prompt(s));
        if (input)
        {
            chdir(input);
            free(input);
        }
        else
        {
            printf("Shuting down\n");
            break;
        }
    }
    return (0);
}