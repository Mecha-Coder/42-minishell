#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

#define IN 0
#define OUT 1

int none_builtin(char *path, char **arg, char **env)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        execve(path, arg, env);
        perror("execlp ls failed");
        exit(EXIT_FAILURE);
    }
    else
        waitpid(child, &status, 0);
    exit(WEXITSTATUS(status));
}

void left(int *fd, int flow, char **env)
{
    char *arg[] = {"ls", NULL};
    char path[] = "/usr/bin/ls";

    close(fd[!flow]);
    dup2(fd[flow], flow);
    none_builtin(path, arg, env);
}

void right(int *fd, int flow, char **env)
{
    char *arg[] = {"wc", "-l", NULL};
    char path[] = "/usr/bin/wc";

    close(fd[!flow]);
    dup2(fd[flow], flow);
    none_builtin(path, arg, env);
}

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
    if (child1 == 0) left(fd, OUT, env);
    else             {waitpid(child1, &status, 0); close(fd[1]);}


    child2 = fork();
    if (child2 == 0) right(fd, IN, env);
    else             {waitpid(child2, &status, 0); close(fd[0]);}
    

    printf("Exit_code: %d\n", WEXITSTATUS(status));
    return 0;
}