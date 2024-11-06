#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PIPE 1
#define CMD 2
#define TRUE 1
#define FALSE 0

typedef struct s_tree
{
    int type;
    struct s_tree *left;
    struct s_tree *right;
    char **cmd;
    char *path;
    char **env;
    int *pipe;
} t_tree;

int none_builtin(t_tree *node);
int run_pipe(t_tree *node);
int run_cmd(t_tree *node);
int descent_tree(t_tree *node);

#endif