/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:24:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/30 06:24:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> get_path
Purpose:
- join each path with file
- check using access() if it's a valid executable 
- If yes, return that joined path
=================================================================
Example

file: ls 
all_path[i] = /usr/bin/

    --> access(/usr/bin/ls)  OK
=================================================================
Return 
char * : Valid path (malloc)
       : NULL - no valid path
*/
char *get_path(char *file, char **all_path)
{
    char *path;
    int i;

    i = -1;
    if (!file || !all_path)
        return (NULL);
    while(all_path[++i])
    {
        path = ft_strjoin(all_path[i], file);
        if (!path)
            err_exit("malloc", errno);
        if (access(path, F_OK | X_OK) == 0)
            return (path);
        free(path);
    }
    return (NULL);
}

/*
void answer(char *s)
{
    char *all_path[4];
    char *path;

    all_path[0] = "/urs/local/bin/";
    all_path[1] = "/local/sbin/";
    all_path[2] = "/usr/bin/";
    all_path[3] = NULL;

    path = get_path(s , all_path);

    if (!path)
        printf("%s: no command found\n", s);
    else
    {
        printf("%s\n", path);
        free(path);
    }
    printf("\n-------------------------------\n");
}

int main()
{
    answer("ls");
    answer("wc");
    answer("lol");
}
*/