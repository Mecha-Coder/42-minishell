/* 
- This is for visual only
- remove after done with project 
*/

#include "../include/minishell.h"

void print_type(int i, char c)
{
    if (c == 'V' || c == 'I')
    {
        if (i == 1)      printf("%-7s", "<AND>");
        else if (i == 2) printf("%-7s","<OR>");
        else if (i == 3) printf("%-7s","<PIPE>");
        else if (i == 4) printf("%-7s","<HERE>");
        else if (i == 5) printf("%-7s","<RD>");
        else if (i == 6) printf("%-7s","<APPD>");
        else if (i == 7) printf("%-7s","<WR>");
        else if (i == 8) printf("%-7s","<OB>");
        else if (i == 9) printf("%-7s","<CB>");
        else if (i == 10) printf("%-7s","<STR>");
    }
    else
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
         else if (i == 10) printf("<STR>");
    }
}

/*
Have horizontal and vertical view
char H -> horizontal
char V -> vertical
*/
void show_token(t_token *current, char c)
{
    while (current)
    {
        if (c == 'D')
        {
            printf("%p\n", current);
            printf("type   : "); print_type(current->type, c);
            printf("\ncontent: [%s]\n", current->content);
            printf("index  : %d\n", current->index);
            printf("prev   : %p\n", current->prev);
            printf("next   : %p\n", current->next);
            printf("\n-------------------------------------\n\n");
        }
        else
        {
            print_type(current->type, c);
            if (c == 'V' && current->type == STR)
                printf(" %s", current->content);
            if (c == 'I')
                printf("%7d", current->index);
            if (c == 'V' || c == 'I')
                printf("\n");
        }
        current = current->next;
    }
    printf("\n");
}
