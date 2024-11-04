#include "../include/minishell.h"

int update_env(char *key, char *val, t_env *env)
{
    char *temp;

    while (env && ft_strcmp(key, env->key))
        env = env->next;
    
    temp = ft_strdup(val);
    if (temp)
    {
        free(env->val);
        env->val = temp;
        return (TRUE);
    }
    return (FALSE);
}