#ifndef SYNTAX_H
#define SYNTAX_H

// Input
int check_bracket(char *s);
int check_occurance(char *s);
int check_quote(char *s);

// Token
int check_combine(t_shell *data);
int check_redirect(t_shell *data);
int check_subshell(t_shell *data);

// Additional check_subshell
t_sub *token_array(t_token *current);
int find_pair(t_sub *sub, int *ob, int *cb);
int check_pair(t_sub *sub, int ob, int cb, char *input);

#endif

