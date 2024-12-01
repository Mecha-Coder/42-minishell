/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:26:40 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 13:42:14 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> manage_io
Purpose: For managing input/output
1) Action  TRUE >> Before do_redirect, snapshot the current I/O
2) Action FALSE >> After done redirect & execute reset previous I/O
*/

void manage_io(int *fd, int action)
{
    if (action)
    {
        fd[STDIN_FILENO] = dup(STDIN_FILENO);
        fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
    }
    else
    {
        dup2(fd[STDIN_FILENO], STDIN_FILENO);
        dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
        close(fd[STDIN_FILENO]);
        close(fd[STDOUT_FILENO]);
    }
}