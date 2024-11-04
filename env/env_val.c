#include "../include/minishell.h"

/* eval_val
Description: Search env for that variable(key) and
    return corresponding value

     USER -> jpaul

Input : Variable name(key) & env linked list 
Output: Value of that variable
    Found     = corresponding value
    Not found = NULL
    NULL key  = NULL

*/
char *env_val(char *key, t_env *env)
{
    while (key && env)
    {
        if (!strcmp(key,env->key))
            return(env->val);
        env = env->next;
    }
    return (NULL);
}