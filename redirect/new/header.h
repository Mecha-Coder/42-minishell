#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>

#define AND 1
#define CMD 2
#define HERE 3
#define STR 4

typedef struct s_token
{
    int type;
    char *content;
    int index;
    int fd;
}   t_token;

typedef struct s_tree
{
    int type;
    t_token *cmd;
    t_token *in;
    t_token *out; 
    struct s_tree *left;
    struct s_tree *right;
    int *pipe;
    int terminate;
}   t_tree;

void visualize_tree(t_tree *node, int level);
#endif