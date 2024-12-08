/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:19:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/04 11:56:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void execute(char *path, char **cmd, char **env);
static void	child(char **cmd, t_env *list);
static void no_cmd_msg(char *command);

/* >>> none_builtin
Purpose: Execute command that is not part of the builtin
==========================================================================
Output Table

-         Abolute path           Relative path               Command
Valid         OK                      OK                        OK
No PATH       OK                      OK                      No dir
Invalid     No dir                  No dir                  No command

Note: All error code is 127
==========================================================================
Return 
int : execution exit code
*/

int none_builtin(char **cmd, t_env *env, int terminate)
{
    pid_t id;
    int status;

    if (terminate)
        child(cmd, env);
    id = fork();
    if (id < 0)
        err_exit("fork", errno);
    else if (!id)
        child(cmd, env);
    waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}

static void	child(char **cmd, t_env *list)
{
    char **all;
    char **env;
    char *path;

    env = env_list(list);
    all = all_path(list);
    if (ft_strchr(cmd[0], '/') || !all)
        execute(cmd[0], cmd, env);
    else
    {
        path = get_path(cmd[0], all);
        if (path)
        {
            execute(path, cmd, env);
            free(path);
        }
        else    
            no_cmd_msg(cmd[0]);
    }
    if (all)
        free_list(all);
    free_list(env);
    exit(127);
}

static void no_cmd_msg(char *command)
{
    ft_putstr_fd(command, 2);
    ft_putstr_fd(": command not found\n", 2);
}

static void execute(char *path, char **cmd, char **env)
{
    execve(path, cmd, env);
    err_msg_3(path, strerror(errno));
}

/*
void answer(char **cmd, char *path)
{
    t_env n1;
    t_env n2;
    t_env n3;

    n1.key = "Hello";
    n1.val = "there";
    n1.next = &n2;

    n2.key = "Haha";
    n2.val = "lala";
    n2.next = &n3;

    n3.key = "PATH";
    n3.val = path;
    n3.next = NULL;

    printf("\nExit code = %d\n", none_builtin(cmd, &n1));
}

int main()
{
    char path[] = "";
    // absolute path - valid / invalid / delete PATH

    // char *s1[] = {"/usr/bin/ls", NULL};
    // char *s2[] = {"/usr/bin/env", NULL};
    // char *s3[] = {"/usr/bin/log", NULL};
    // char *s4[] = {"/dsads/dssda/dsas", NULL};

    
    //--------------------------------------------------

    // relative path - valid / invalid / delete PATH

    // char *s5[] = {"/bin/ls", NULL};
    // char *s6[] = {"/bin/env", NULL};
    // char *s7[] = {"/dsas", NULL};

   //--------------------------------------------------

    // command - valid / invalid / deleted PATH
    
    // char *s8[] = {"ls", NULL};
    // char *s9[] = {"env", NULL};
    char *s10[] = {"dsadad", NULL};

        answer(s10, path);
}
*/