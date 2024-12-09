#ifndef ENV_H
#define ENV_H

void setup_env(t_shell *data, char **env);
void destroy_env(t_shell *data);
char **env_list(t_env *env);
char *env_val(char *key, t_env *env);
int env_len(t_env *env);
int update_env(char *key, char *val, t_env *env);
int append_env(char *key, char *val, t_env *env);

#endif