/* 
- This is for visual only
- remove after done with project 
*/

#include "../include/minishell.h"

void print_type(int i)
{
    if (i == 1)      printf("<AND>");
    else if (i == 2) printf("<OR>");
    else if (i == 3) printf("<PIPE>");
    else if (i == 4) printf("<HERE>");
    else if (i == 5) printf("<RD>");
    else if (i == 6) printf("<APPD>");
    else if (i == 7) printf("<WR>");
    else if (i == 8) printf("<OB>");
    else if (i == 9) printf("<CB>");
}

void show_token(t_token *current)
{
    while (current)
    {
        print_type(current->type);
        if (current->type == STR)
            printf(" %s", current->content);
        current = current->next;
        printf("\n");
    }
}
