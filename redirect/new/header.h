#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <fcntl.h>

#define AND 1
#define CMD 2
#define HERE 3
#define STR 4
#define RD 5
#define WR 6

typedef struct s_token
{
    int type;
    char *content;
    int index;
    int herefd[2];
    int fd;
}   t_token;


typedef struct s_tree
{
    t_token *info;
    int type;
    char **arg;
    char *path;
    t_token *in;
    t_token *out; 
    struct s_tree *left;
    struct s_tree *right;
    int *pipe;
    int terminate;
}   t_tree;

void visualize_tree(t_tree *node, int level);
void heredoc(int *fd, char *delimiter);
#endif