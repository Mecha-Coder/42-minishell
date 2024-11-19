#ifndef EXPAND_H
#define EXPAND_H

// Variable
void sub_squote(char *s, int sub);
void del_quote(char *s, int type);
void exit_2_str(char *s, int code);
char *insert_var(char *s, t_shell *data);
char *insert_exit(char *s, int *i, int code);
char *insert_value(char *s, int *i, int len, t_env *env);
char *exp_var(char *s, t_shell *data);

// Wildcard
int wildcard_match(char *entry, char *pattern);
t_token *exp_wild_str(char *pattern);

#endif