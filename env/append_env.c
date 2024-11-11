#include "../include/minishell.h"

int append_env(char *key, char *val, t_env *env)
{
    t_env *new;
   
    new = (t_env *)malloc(sizeof(t_env));
    if (!new)
        return (FALSE);

    new->key = ft_strdup(key);
    new->val = ft_strdup(val);
    new->next = NULL;
    if (!new->key || !new->val)
    {
        if (new->key)
            free(new->key);
        if (new->val)
            free(new->key);
        free(new);
        return (FALSE);
    }
    
    while (env->next)
        env = env->next;
    env->next = new;
    return (TRUE);
}