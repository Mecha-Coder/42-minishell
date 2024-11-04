#include "../include/minishell.h"

int env_len(t_env *env)
{
    int i;

    i = 0;
    while (env && ++i)
        env = env->next;
    return (i);
}
