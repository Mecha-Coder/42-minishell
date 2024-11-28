/* 
- This is for visual only
- remove after done with project 
*/

#include "../include/minishell.h"

/*
Type of token views
- horizontal
    type: H   <STR><RD><PIPE><WR><AND>     
    type: C   <STR>Hello <WR>out.txt

- vertical
    type: V   <STR>   Hello
              <STR>   there
              <PIPE>
    
    type: I   <STR>   0
              <PIPE>  5
              <OB>    8

- printf all member of the token node (detailed)
    type: D
*/
void show_token(t_token *current, char type)
{
    while (current)
    {
        if (type == 'D')
        {
            printf("%p\n", current);
            printf("type   : ");  print_type_2(current->type);
            printf("\ncontent: [%s]\n", current->content);
            printf("index  : %d\n", current->index);
            printf("prev   : %p\n", current->prev);
            printf("next   : %p\n", current->next);
            printf("\n-------------------------------------\n\n");
        }
        else if (type == 'V' || type == 'I')
        {
            print_type_1(current->type);
            if (type == 'V' && current->type == STR)
                printf("%s", current->content);
            if (type == 'I')
                printf("%7d", current->index);
            printf("\n");
        }
        else if (type == 'H' || type == 'C')
        {
            print_type_2(current->type);
            if (type == 'C' && current->content)
                printf("%s ", current->content);
            else
                printf("NULL ");
        }
        current = current->next;
    }
    printf("\n");
}
