#ifndef TOKEN_H
#define TOKEN_H

void tokenize(t_shell *data);
void destroy_token(t_token *token);
t_token *create_token(int type, char *content, int index, t_token *prev_token);
t_token *token_relink(t_token *current, t_token *new);
t_token *token_jumpback(t_token *current);
t_token *token_jumpfront(t_token *current);
t_token *sort_token(t_token *head, char c);
t_token *extract_operator(char *s);
t_token *extract_word(char *s, int sub);



#endif
