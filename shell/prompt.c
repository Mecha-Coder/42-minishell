/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:39:34 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 20:04:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void reset_prompt(t_shell *data);
static void prev_status(char *s, int code);
static int prep_token_for_ast(t_shell *data);

/* >>> prompt
Purpose: Show prompt and wait for input. This makes the shell interective
*/

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
            if (prep_token_for_ast(data))  
            {
                build_ast(data);
                 if (run_here(data->tree, data) == 1)
                    continue ;
                run_ast(data);
            }
            reset_prompt(data);
        }
        else
            break;
        signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
    }
}

static int prep_token_for_ast(t_shell *data)
{
    if (!is_empty(data->input) && input_syntax(data))  
    {
        tokenize(data);
        if (token_syntax(data))
            return (TRUE);
    }
    return (FALSE);
}

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

