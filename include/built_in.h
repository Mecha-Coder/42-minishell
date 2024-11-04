#ifndef BUILT_IN_H
# define BUILT_IN_H


void ft_export (char **arg, t_env *env);
void ft_unset(char **arg, t_shell *data);
void ft_echo(char **arg, t_shell *data);
void	ft_pwd();
void	ft_cd(char **args, t_shell *data);
void	ft_exit(char **args, t_shell *data);
void	ft_env(char **args, t_shell *data);

# endif