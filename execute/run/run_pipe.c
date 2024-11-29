/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:24:09 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:08:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void left(int *fd, t_tree *node, t_shell *data);
static void right(int *fd, t_tree *node, t_shell *data);

int run_pipe(t_tree *node, t_shell *data)
{
    int fd[2];
    int status;
    pid_t id_1;
    pid_t id_2;

    if (pipe(fd) < 0) 
        err_exit("pipe", errno);
    node->left->pipe = fd;
    node->left->terminate = TRUE;
    node->right->terminate = TRUE;

    id_1 = fork();
    if (id_1 < 0)
        err_exit("fork", errno);
    else if (id_1 == 0)
        left(fd, node, data);
    
    id_2 = fork();
    if (id_2 < 0)
        err_exit("fork", errno);
    else if (id_2 == 0)
        right(fd, node, data);

    close(fd[0]);
    close(fd[1]);
    waitpid(id_1, &status, 0);
    waitpid(id_2, &status, 0);
    return (WEXITSTATUS(status));
}

static void left(int *fd, t_tree *node, t_shell *data)
{
    if (node->left->type == EXE ||
        node->left->type == SUB)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
    }
    descent_tree(node->left, data);
}

static void right(int *fd, t_tree *node, t_shell *data)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
        close(node->pipe[1]);
    }
    descent_tree(node->right, data);
}