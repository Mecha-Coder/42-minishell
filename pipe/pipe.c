#include "header.h"

int main(int ac, char **av, char **env)
{
    int fd[2];
    pid_t child1;
    pid_t child2;
    int status;

    (void)ac;
    (void)av;

    pipe(fd);
    child1 = fork();
    if (child1 == 0) 
    {
        char *arg[] = {"ls", NULL};
        char path[] = "/usr/bin/ls";

        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        none_builtin(path, arg, env);
    }
  

    child2 = fork();
    if (child2 == 0)
    {
        char *arg[] = {"wc", "-l", NULL};
        char path[] = "/usr/bin/wc";

        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        none_builtin(path, arg, env);
    }
   
    
    close(fd[0]);
    close(fd[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
    printf("Exit_code: %d\n", WEXITSTATUS(status));
    return 0;
}