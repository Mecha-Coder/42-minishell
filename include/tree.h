#ifndef TREE_H
#define TREE_H

void merge_redirect(t_token *current);
void build_ast(t_shell *data);
t_tree *create_tree(t_token *token);

#endif