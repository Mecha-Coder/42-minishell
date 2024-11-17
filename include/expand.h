#ifndef EXPAND_H
#define EXPAND_H

void sub_squote(char *s, int sub);
void del_quote(char *s, int type);
void exit_2_str(char *s, int code);
char *insert_var(char *s, t_shell *data);

#endif