#ifndef EXECUTE_H
#define EXECUTE_H

// None_builtin
char **all_path(t_env *env);
char *get_path(char *file, char **all_path);
int none_builtin(char **cmd, t_env *list);

// Run
void run_ast(t_shell *data);
char **prep_arg(t_token *current);
int descent_tree(t_tree *node, t_shell *data);
int run_and(t_tree *node, t_shell *data);
int run_or(t_tree *node, t_shell *data);
int run_exe(t_tree *node, t_shell *data);
int run_pipe(t_tree *node, t_shell *data);
int run_subshell(t_tree *node, t_shell *data);


#endif