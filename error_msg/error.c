#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char s[] = "dsada";
    int fd = open(s, O_RDONLY);
    if (fd == -1)
    {
        write(2, "minishell:  cd: ", sizeof("minishell:  cd: "));
        ft_putstr_fd("minishell:  cd: ", 2);
        perror(s);
        //printf("open: %s\n", strerror(errno));
    }    
    else
        printf("OK\n");
}