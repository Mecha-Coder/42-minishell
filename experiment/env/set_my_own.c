#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_set_env(char ***envp, const char *key, const char *value)
{
    int i = 0;
    char *env_str;
    char **new_envp;

    env_str = malloc(strlen(key) + strlen(value) + 2);
    if (env_str == NULL) 
        (perror("malloc"), exit(1));
    sprintf(env_str, "%s=%s", key, value);


    while ((*envp)[i] != NULL) 
    {
        if (strncmp((*envp)[i], key, strlen(key)) == 0 
            && (*envp)[i][strlen(key)] == '=') 
        {
            (*envp)[i] = env_str;
            return;
        }
        i++;
    }

    new_envp = realloc(*envp, sizeof(char *) * (i + 2));
    if (new_envp == NULL)
        (perror("realloc"), free(env_str), exit(1));
    
    *envp = new_envp;
    (*envp)[i] = env_str;
    (*envp)[i + 1] = NULL;
}

int main(int ac, char **av, char **envp) 
{
    (void)ac;
    (void)av;
    printf("Initial MY_VAR: %s\n", getenv("MY_VAR"));
    my_set_env(&envp, "MY_VAR", "my_value");
    printf("Modified MY_VAR: %s\n", getenv("MY_VAR"));

    return 0;
}
