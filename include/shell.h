#ifndef SHELL_H
#define SHELL_H

int input_syntax(t_shell *data);
int token_syntax(t_shell *data);
void prompt(t_shell *data);
void initialize(t_shell *data, char **env);
void close_shell(int code, t_shell *data);

#endif