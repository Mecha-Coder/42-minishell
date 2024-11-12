#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>

typedef struct s_list
{
    char *s;
    struct s_list *next;
}   t_list;

t_list *create_list()
{
    t_list *new = (t_list*)malloc(sizeof(t_list *));
    if (new)
        memset(new, 0, sizeof(t_list));
    return (new);
}

int main() 
{
    char *input;
    char *delimiter = "DONE";
    t_list *head = create_list();
    t_list *current = head;

    while (1)
    {
        input = readline("> ");
        if (!input)
        {
            printf("warning: here-document delimited by end-of-file (wanted `%s')\n", delimiter);
            exit(EXIT_SUCCESS);
        }
        if (!strcmp(input, delimiter))
        {
            free (input);
            current = head;
            while (current->s)
            {
                printf("%s\n", current->s);
                current = current->next;
            }
            exit(EXIT_SUCCESS);
            
        }
        current->s = input;
        current->next = create_list();
        current = current->next;
    }

    return 0;
}