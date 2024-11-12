#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <stdio.h>

void prompt_heredoc(int fd, char *delimiter) {
    char *input;

    while (1) 
    {
        input = readline("> ");
        if (!input) 
        {
            printf("warning: here-document delimited by end-of-file (wanted `%s')\n", delimiter);
            return ; 
        }
        if (!strcmp(input, delimiter))
        {
            free(input);
            return ;
        }
        write(fd, input, strlen(input));
        write(fd, "\n", 1);

        free(input);
    }
}

void heredoc(int *fd, char *delimiter)
{
    if (fd[0] > 2 && fd[1] > 2)
    {
        close(fd[0]);
        close(fd[1]);
    }

    if (pipe(fd) < 0) 
    {
        perror("pipe");
        return ;
    }

    prompt_heredoc(fd[1], delimiter);
}


int main()
{
    int fd[2];
    int status;
    pid_t id;

    memset(fd, -1, sizeof(fd));

    heredoc(fd, "EOF");
    printf("Testing\n");
    heredoc(fd, "DONE");

    
    id = fork();
    if (!id)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);

        char *argv[] = {"cat", NULL};
        execve("/usr/bin/cat", argv, NULL);
        perror("execute");
        exit(EXIT_FAILURE);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(id, &status, 0);
    return 0;
}