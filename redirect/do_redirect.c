/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:09:18 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/28 22:09:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	open_file(char *file, int filemode);

/* >>> do_redirect
Purpose: Read the redirect token, using dup2 to change STDIN & STDOUT

=======================================================================
Return 
int 
    TRUE: Redirect successful
    FALSE: Failed to open file

Note: if file opening failed update cmd_exit_code and stop execution
*/

int do_redirect(t_token *current)
{
    int fd;

    while (current)
    {
        if (current->type == HERE)
        {
            dup2(current->herefd[0], STDIN_FILENO);
            close(current->herefd[0]);
        }
        else if (current->type != STR)
        {
            fd = open_file(current->content, current->type);
            if (fd == -1)
                return (FALSE);
            if (current->type == WR || current->type == APPD )
                dup2(fd, STDOUT_FILENO);
            else if (current->type == RD)
                dup2(fd, STDIN_FILENO);
            close(fd);
        }
        current = current->next;
    }
    return (TRUE);
}

static int	open_file(char *file, int filemode)
{
	int	fd;

	if (filemode == RD)
		fd = open(file, O_RDONLY, 0777);
	if (filemode == WR)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filemode == APPD)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
        err_msg_3(file, strerror(errno));
    return (fd);
}

/*
int main()
{
    t_token t;
    // int readnum;
    // int size = 20;
    // char buffer[size];
    char sample[] = "Hello the pipe";
    int oriterm[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

    // printf("\nRead file\n=================\n");
    // t.type = RD;
    // t.content = "in";
    // t.next = NULL;

    //     do_redirect(&t);
    //     readnum = read(STDIN_FILENO, buffer, size);
    //     write(STDOUT_FILENO, buffer, readnum);
    //     printf("\n");
  
    // dup2(oriterm[STDIN_FILENO], STDIN_FILENO);
    // dup2(oriterm[STDOUT_FILENO], STDOUT_FILENO);

    // printf("\nRead heredoc\n=================\n");
    // t.type = HERE;
    // t.content = NULL;
    // t.next = NULL;
    // pipe(t.herefd);
    // write(t.herefd[1], sample, ft_strlen(sample));
    
    //     do_redirect(&t);
    //     readnum = read(STDIN_FILENO, buffer, size);
    //     write(STDOUT_FILENO, buffer, readnum);
    //     printf("\n");

    // close(t.herefd[0]);
    // close(t.herefd[1]);

    // dup2(oriterm[STDIN_FILENO], STDIN_FILENO);
    // dup2(oriterm[STDOUT_FILENO], STDOUT_FILENO);

    // printf("\nWrite file\n=================\n");
    // t.type = WR;
    // t.content = "out";
    // t.next = NULL;
   
    //     do_redirect(&t);
    //     write(STDOUT_FILENO, sample, ft_strlen(sample));
    //     printf("\n");

    // dup2(oriterm[STDIN_FILENO], STDIN_FILENO);
    // dup2(oriterm[STDOUT_FILENO], STDOUT_FILENO);

    printf("\nAppend file\n=================\n");
    t.type = APPD;
    t.content = "out";
    t.next = NULL;
   
        do_redirect(&t);
        write(STDOUT_FILENO, sample, ft_strlen(sample));
        printf("\n");

        char *arg[] = {"ls", NULL}; 
        printf("Testing if printf can ...\n");
        execve("/usr/bin/ls", arg , NULL);

    dup2(oriterm[STDIN_FILENO], STDIN_FILENO);
    dup2(oriterm[STDOUT_FILENO], STDOUT_FILENO);
}
*/
