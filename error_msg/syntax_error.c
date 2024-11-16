#include <stdio.h>


#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"

int main()
{
    printf("                       ↓\n" GREEN
           "echo \"Double ' quote: \"\"\n" RESET
           "minishell: syntax error\n"
    );
}