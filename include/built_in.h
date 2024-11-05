#ifndef BUILT_IN_H
# define BUILT_IN_H

int    ft_pwd();
int    ft_clear();
int    ft_echo(char **args);
int    ft_export (char **args, t_shell *env);
int    ft_unset(char **args, t_shell *data);
int    ft_cd(char **args, t_shell *data);
int    ft_env(char **args, t_shell *data);
int    ft_exit(char **args, t_shell *data);

# endif