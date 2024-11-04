#ifndef ENV_H
#define ENV_H

#include "../struct.h"

int setup_env(t_shell *data, char **env);
void destroy_env(t_shell *data);
char **env_list(t_env *env);
int env_len(t_env *env);
char *env_val(char *key, t_env *env);

#endif