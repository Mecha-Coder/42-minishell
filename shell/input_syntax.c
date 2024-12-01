/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:26 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 20:04:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >> check_input_syntax
Purpose: 
- Check quote, operator symbol occurance and bracket placement
- If invalid syntax, stop checking and update cmd_exit_no to 1

===================================================================
Return
    TRUE  : Correct syntax
    FALSE : vice versa
*/
int input_syntax(t_shell *data)
{
    add_history(data->input);
    if (!check_quote(data->input) 
        || !check_bracket(data->input) 
        || !check_occurance(data->input))
    {
        data->cmd_exit_no = 2;
        return (FALSE);
    }
    return (TRUE);
}