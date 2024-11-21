#include "../../include/minishell.h"



t_pair create_pair()

t_pair *get_pair(t_token *current)
{

}

int main()
{
    t_shell data;

    data.input = "echo lo && (echo nice && (ls)) && ((echo hi) && (ls) && (ls)) && (ls && (ls && (ls)))";
    tokenize(&data);
    t_pair = get_pair(data.token);
}