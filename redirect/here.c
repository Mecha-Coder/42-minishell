#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <sys/wait.h>

// gcc readline.c -lreadline

void prompt_here(int fd, char *delimiter)
{
    char *input;

    while (1)
    {
        input = readline("> ");
        if (!input)
        {
            write(STDIN_FILENO, "EOF error\n", sizeof("EOF error"));
            exit (EXIT_FAILURE);
        }
        if (!strcmp(input, delimiter))
            exit(EXIT_SUCCESS);
        write(fd, input, strlen(input));
        write(fd, "\n", 1);
        free(input);
    }
}


int main()
{
    int fd[2];
    pid_t id_1;
    pid_t id_2;


    pipe(fd);
    id_1 = fork();
    if (!id_1)
    {
        close(fd[0]);
        prompt_here(fd[1], "EOF");
    }

    id_2 = fork();
    if (!id_2)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        char *argv[] = {"cat", NULL};
        execve("/usr/bin/cat", argv, NULL);
    }
    
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

}