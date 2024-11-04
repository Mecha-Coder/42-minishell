#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int run_cmd(int flag)
{
    if (flag)
        exit (255);
    return (255);
} 

int main()
{
    int status;
    pid_t child;

    child = fork();
    if (child == 0)
        run_cmd(1);

    waitpid(child ,&status, 0);
    printf("Exit_code: %d\n", WEXITSTATUS(status));

}