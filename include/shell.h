#ifndef SHELL_H
#define SHELL_H

void initialize(t_shell *data, char **env);
int check_input_syntax(t_shell *data);
int check_token_syntax(t_shell *data);

#endif