#ifndef TREE_H
#define TREE_H

void destroy_tree(t_tree *node);
void merge_redirect(t_token *current);
void build_ast(t_shell *data);
int branch_combine(t_tree *node);
int branch_subshell(t_tree *node);
t_tree *create_tree(t_token *token);

#endif