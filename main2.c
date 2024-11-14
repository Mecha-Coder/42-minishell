#include "include/minishell.h"

int parse(t_shell *data)
{
    if (is_empty(data->input))                return (FALSE);
    if (ft_strlen(data->input) >= BUFFER_SIZE)  return (printf(LONG_INPUT), FALSE);
    
    add_history(data->input);
    ft_strcpy(data->s, data->input);
    data->s_len = ft_strlen(data->s);

    return (check_syntax_before(data)
        && tokenize(data)
        && check_syntax_after(data)
        && build_ast(data));
}

void reset(t_shell *data)
{
    destroy_ast(data);
    free_str_token(data);
}

void prompt(char *s, int num)
{
    int len = 13;
    if (num)
        s[6] = '1';
    else
        s[6] = '6';
    while (len > 10)
    {
        s[len--] = (num % 10) + '0';
        num /= 10;
    }
}

void interective_mode(t_shell *data)
{
    char s[40];

    ft_strcpy(s, PROMPT);
    rl_on_new_line();
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, SIG_IGN);
    while (1)
    {
        prompt(s, data->cmd_exit_no);
        data->input = readline(s);
        if (data->input)
        {
            if (parse(data))  
            {
                run_ast(data);
                reset(data);
            }
            free(data->input);
            rl_on_new_line();
        }
        else
        {
            printf(SHUTDOWN);
            break;
        }
    }
}

int main(int ac, char **av, char **env)
{
    t_shell data;

    (void)ac;
    (void)av;
    if (!setup_env(&data, env)) exit(EXIT_FAILURE);
    data.cmd_exit_no = 0;

    interective_mode(&data);

    destroy_env(&data);
    rl_clear_history();
    return (0);
}
