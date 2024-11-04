#include "../include/minishell.h"

static char *concat_key_val(char *s, t_env *env);

/* Test
int main()
{
    char **list;
    int i = -1;

    t_env n1;
    t_env n2;
    t_env n3;

    n1.key = "HOME";
    n1.val = "/home/jpaul";
    n1.next = &n2;

    n2.key = "USER";
    n2.val = "Jason";
    n2.next = &n3;

    n3.key = "SHELL";
    n3.val = "/bash/";
    n3.next = NULL;

    list = env_array(&n1);
    while (list && list[++i]) 
        printf("%s\n", list[i]);
    free_list(list);
}
*/

/* env_array
Description: Convert env in struct to 2D array

Input: Pointer to env linked-list head
    key: USER
    val: jpaul

Output: 2D array version of the env
    * array = {"USER=jpaul", NULL}
    * NULL if malloc fail
*/
char **env_list(t_env *env)
{
    int i;
    int total;
    char *s;
    char **list;

    i = 0;
    list = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
    if (!list)
        return (NULL);
    while (env)
    { 
        total = strlen(env->key) + strlen(env->val) + 2;
        s = (char *)malloc(total);
        if (!s)
            return (free_list(list), NULL);
        list[i++] =  concat_key_val(s, env);
        env = env->next;
    }
    list[i] = NULL;
    return (list);
}

static char *concat_key_val(char *s, t_env *env)
{
    strcpy(s, env->key);
    strcat(s,"=");
    strcat(s, env->val);
    return (s);
}