#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int run_cmd(int flag)
{
    int status;

    if (flag)
        exit (255);
    return (status);
} 


int main()
{
    int status;
    pid_t child;

    status = 43523;
    child = fork();
    if (child == 0)
    {
        run_cmd(0);
        printf("Child: %d\n", WEXITSTATUS(status));
    }
        
    else
    {
        waitpid(child ,&status, 0);
        printf("Parent: %d\n", WEXITSTATUS(status));
    }
        
}