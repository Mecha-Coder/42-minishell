/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:39:34 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/05 15:10:41 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void reset_prompt(t_shell *data);
static void prev_status(char *s, int code);

/* >>> prompt
Purpose: Show propmt and wait for input. This makes the shell interective
*/

static void reset_prompt(t_shell *data)
{
    if (data->input)
	    free(data->input);
    destroy_tree(data->tree);
    data->input = NULL;
    data->tree = NULL;
    data->token = NULL;
    rl_on_new_line();
}

static void prev_status(char *s, int code)
{
    if (code)
        s[6] = '1';
    else
        s[6] = '6';
}

void prompt(t_shell *data)
{
    char s[40];

    ft_strcpy(s, PROMPT);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
    while (1)
    {
        prev_status(s, data->cmd_exit_no);
        data->input = readline(s);
        if (data->input)
        {
            if (!is_empty(data->input) && input_syntax(data))  
            {
                tokenize(data);
                if (token_syntax(data))
                {
                    build_ast(data);
                    if (run_heredoc(data->tree) == 1)
                        continue ;
                    run_ast(data);
                }
            }
            reset_prompt(data);
        }
        else
            break;
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
    }
}
