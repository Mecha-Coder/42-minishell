#ifndef UTILS_H
#define UTILS_H

#include "struct.h"

int blank_char(char c);
int detection(char c, int *state);
int is_empty(char *s);
void point_index(int index);
int token_len(t_token *token);
void free_list(char **list);
char *join_str(char *s1, char *s2);
char *get_var(char *key, t_env *current);
int is_identifier(char *s, int *i);

void	err_msg_1(char *builtin, char *arg, char *msg);
void	err_msg_2(char *builtin, char *arg, char *msg);
void	err_msg_3(char *builtin, char *msg);
int	    arg_count(char **args, char *builtin);

#endif