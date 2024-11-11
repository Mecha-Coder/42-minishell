#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 

int	child(char **env)
{
    pid_t id;
    int status;
	char *path = "/usr/bin/ls";
    char *cmd[] = {"ls", NULL};

    id = fork();
    if (id < 0) {perror("fork failed"); exit(EXIT_FAILURE);}
    else if (!id)
    {
        execve(path, cmd, env);
        printf("Fail execution");
	    exit(EXIT_FAILURE);
    }
    else
        waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}


int descent_tree(char **env)
{
    int status;

    status = child(env);
    if (0)
        exit(status);
    return (status);
}

void main(int ac, char **av, char **env)
{
   int status;
    pid_t id;

    (void)ac;
    (void)av;
    id = fork();
    if (id == 0)
    {
        descent_tree(env);
        printf("child %d\n", WEXITSTATUS(status));
    } 
    else
    {
        waitpid(id, &status, 0);
        printf("parent %d\n", WEXITSTATUS(status));
    }
}