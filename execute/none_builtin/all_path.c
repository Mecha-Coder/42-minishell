/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:15:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 13:34:40 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char **allocate_path(char *s);
static char *extract_path(char *s, int size);

/* >>> all_path
Purpose: 
- Search in env for "PATH" key 
- Get value and split "PATH" string into individual paths
- Put paths into malloc array
=======================================================================
Example: 

env_path -->  /urs/local/bin:/local/sbin:/usr/bin\0
         -->  /urs/local/bin\0
         -->  \0

-> /usr/local/bin/
-> /loca/sbin/
-> /usr/bin/

Note: 
- Delimited by ':' and '\0'
=======================================================================
Caution:
- PATH in env can be edit and delete. Handle this
=======================================================================
Return
- char ** : 2D array (malloc)
          : NULL if env PATH is blank
*/

char **all_path(t_env *env)
{
    char *s;
    char **all;
    int i;
    int j;

    (i = 0, j = 0);
    s = env_val("PATH", env);
    if (!s || is_empty(s))
        return (NULL);
    all = allocate_path(s);
    while(1)
    {
        if (s[i] == ':' || s[i] == '\0')
        {
            all[j++] = extract_path(s, i);
            if (s[i] == '\0')
                break ;
            s = &s[i + 1];
            i = 0;
        }
        else
            i++;
    }
    all[j] = NULL;
    return (all);
}

static char *extract_path(char *s, int size)
{
    char *new;

    new = (char *)malloc(size + 2);
    if (!new)
        err_exit("malloc", errno);
    ft_strlcpy(new, s, size + 1);
    ft_strcat(new, "/");
    return (new); 
}

static char **allocate_path(char *s)
{
    int i;
    char **array;

    i = 0;
    while(s && *s)
    {
        if (*s == ':')
            i++;
        s++;
    }
    array = (char **)malloc(sizeof(char *) * (i + 2));
    if (!array)
        err_exit("malloc", errno);
    return (array);
}

/*
void answer(char *s)
{
    t_env n1;
    t_env n2;
    t_env n3;
    char **path;
    int i = -1;

    n1.key = "Hello";
    n1.val = "there";
    n1.next = &n2;

    n2.key = "Haha";
    n2.val = "lala";
    n2.next = &n3;

    n3.key = "PATH";
    n3.val = s;
    n3.next = NULL;

    path = all_path(&n1);
    while (path[++i])
        printf("%d) [%s]\n", i, path[i]);
    free_list(path);

    printf("\n-------------------------\n");
}

int main()
{
    answer("/urs/local/bin:/local/sbin:/usr/bin/log");
    answer("/urs/local/bin:/local/sbin");
    answer("/urs/local/bin");
}
*/