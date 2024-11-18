#ifndef UTILS_H
#define UTILS_H

#include "struct.h"

int detection(char c, int *state);
char *join3(char *s1, char *s2, char *s3);
int is_identifier(char *s, int *i);
void free_list(char **list);

void	err_msg_1(char *builtin, char *arg, char *msg);
void	err_msg_2(char *builtin, char *arg, char *msg);
void	err_msg_3(char *builtin, char *msg);
void    err_msg_syntax(char *input, char *msg, int index);
int	    arg_count(char **args, char *builtin);

#endif