#include "../../include/minishell.h"




int main()
{
    t_shell data;

    data.input = "echo lo && (echo nice && (ls)) && ((echo hi) && (ls) && (ls)) && (ls && (ls && (ls)))";
    tokenize(&data);
    t_pair *list = get_pair(data.token);



    destroy_pair(list);
    destroy_token(data.token);
}


void point_index(int index)
{
    while(i++ < index)
		printf(" ");
	printf("↓\n");
}