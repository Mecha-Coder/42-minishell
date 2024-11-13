#include "header.h"

static void prompt_heredoc(int fd, char *delimiter);

/*
Handle heredoc prompt
*/
void heredoc(int *fd, char *delimiter)
{
    if (pipe(fd) < 0) 
    {
        perror("pipe");
        return ;
    }
    prompt_heredoc(fd[1], delimiter);
}


static void prompt_heredoc(int fd, char *delimiter)
{
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
