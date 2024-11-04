#ifndef BUILT_IN_H
# define BUILT_IN_H

// EXPORT
void builtin_export (char **arg, t_env *env);
void print_sorted_env(t_env *env);
int update_env(char *key, char *val, t_env *env);
int append_env(char *key, char *val, t_env *env);


// UNSET
void builtin_unset(char **arg, t_shell *data);
# endif