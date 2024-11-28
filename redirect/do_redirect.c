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

int	open_file(char *file, int filemode);

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
            close(current->herefd[1]);
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
        current = current->next
    }
    return (TRUE);
}

int	open_file(char *file, int filemode)
{
	int	fd;

	if (filemode == RD)
		fd = open(file, O_RDONLY, 0777);
	if (filemode == WR)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filemode == APPD)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
        err_msg_3(current->content, strerror(errno));
    return (fd);
}