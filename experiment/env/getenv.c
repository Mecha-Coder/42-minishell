#include <stdio.h>
#include <stdlib.h>

/*
To study the getenv() function behavior.
Exmaple:
    SHELL is a environment variable (Remove $ from $SHELL)
    Pass in answer = getenv("SHELL")

PROTOTYPE
char *getenv(const char *name)

return
 OK > string pointer
KO > NULL

*/

int main(int ac, char **av)
{    
    char *env_var_name;
    char *env_var_value;

    if (ac == 2 && av[1])
    {
        env_var_name = av[1];
        env_var_value = getenv(env_var_name);

        if (env_var_value)
            printf("%s = %s\n", env_var_name, env_var_value);
        else
            printf("Environment variable %s not found.\n", env_var_name);
    }
   
    return 0;
}