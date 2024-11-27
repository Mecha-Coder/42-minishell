#ifndef UTILS_H
#define UTILS_H

#include "struct.h"

int detection(char c, int *state, int sub);
char *join3(char *s1, char *s2, char *s3);
int is_identifier(char *s, int *i);
void free_list(char **list);
int find_word(char *s, char *word);
int is_empty(char *s);
int word_count(char *s);

void	err_msg_1(char *builtin, char *arg, char *msg);
void	err_msg_2(char *builtin, char *arg, char *msg);
void	err_msg_3(char *builtin, char *msg);
void    err_msg_4(char *input, char *msg, int index);
int	    arg_count(char **args, char *builtin);

#endif