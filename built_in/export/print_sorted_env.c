#include "../../include/minishell.h"

static char **env_key_list(t_env *env);
static void sort_list(char **list);

/* Test 
int main(int ac, char **av, char **env)
{
     t_shell data;
    (void)ac;
    (void)av;

    setup_env(&data, env);
    print_sorted_env(data.env);
    destroy_env(&data);
}
*/

/* print_sorted_env
Description: Display env list in ascending order
*/
void print_sorted_env(t_env *env)
{
    int i;
    char **list;

    i = -1;
    list = env_key_list(env);
    if (!list)
        return ;
    sort_list(list);
    while (list[++i])
        printf("declare -x %s=\"%s\"\n", list[i], env_val(list[i], env));
    free(list);
}

static char **env_key_list(t_env *env)
{
    int i;
    char **list;
    
    i = 0;
    list = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
    if (!list)
        return (NULL);
    while (env)
    {
        list[i++] = env->key;   
        env = env->next;
    }
    list[i] = NULL;
    return (list);
}

static void sort_list(char **list)
{
    char *temp;
    int i;
    int len;

    (i = 1 , len = 0);
    while (list && list[len])
        len++;
    while (--len)
    {
        i = -1;
        while (++i < len)
        {
            if (strcmp(list[i], list[i + 1]) > 0)
            {
                temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }
    }
}