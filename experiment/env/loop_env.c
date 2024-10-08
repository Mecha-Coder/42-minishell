#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    int i = -1; 
    
    (void)ac;
    (void)av;
    while (env[++i])
        printf("%d) %s\n", i, env[i]);
    return (0);
}