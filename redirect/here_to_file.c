#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <fcntl.h>

int main() 
{
    char *input;
    char *delimiter = "DONE";

    int fd = open("dummy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);

    while (1)
    {
        input = readline("> ");
        if (!input)
        {
            printf("warning: here-document delimited by end-of-file (wanted `%s')\n", delimiter);
            close(fd);
            exit(EXIT_SUCCESS);
        }
        if (!strcmp(input, delimiter))
        {
            free(input);
            close(fd);
            exit(EXIT_SUCCESS);
        }
        write(fd, input, strlen(input));
        write(fd, "\n", 1);
        free(input);
    }
    return 0;
}