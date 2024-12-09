/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:51:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/09 09:51:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> get_status
Purpose: 
- This funciton is used to get the exit_code for a child process.
- Called after waitpid()
====================================================================
Param
- int status -> same status give to waitpid 
*/

int get_status(int status)
{
    int exit_code;

    if (WIFSIGNALED(status))
    {
        exit_code = WTERMSIG(status);
        if (exit_code == 2)
            g_sig = TRUE;
        return (exit_code + 128);
    }
    return (WEXITSTATUS(status));
}