/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:24 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 11:31:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >> check_token_syntax
Purpose: 
- Check operator placement for combine, redirect & subshell follow rule
- If invalid syntax, stop checking and 
    * update cmd_exit_no to 1
    * free token

===================================================================
Return
    TRUE  : Correct syntax
    FALSE : vice versa
*/
int check_token_syntax(t_shell *data)
{
    if (!check_redirect(data)
        || !check_combine(data)
        || !check_subshell(data))
    {
        data->cmd_exit_no = 1;
        destroy_token(data->token);
        return (FALSE);
    }
    return (TRUE);
}