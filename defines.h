#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_env
{
    char *key;
    char *val;
    struct s_env *next;
} t_env;

typedef struct s_file
{
    int mode;
    char file[100];
    int fd;
    struct s_file *next;
} t_file;

typedef struct s_tree
{
    char **cmd;
    char **out;
} t_tree;

typedef struct s_shell
{
    int exit_code; // 1
    int interactive_mode;
    char *input;
    t_env *env;

} t_shell;

#endif