/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:02:02 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/27 11:41:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define ERR_REDIR "ambiguous redirect"

/* >>> expand_redir
Purpose: If token is tredirect, expand accordingly

============================================================
Steps to expand redirect

1) Expand variable
2) Perform word count, error if != 1
3) Expand wildcard
    return FALSE : Found > 1 matching file, error
    return TRUE  : Found 1 or none matching file
4) Eval wildcard result
    No matching : leave as is
    1 match     : update filename
DONE
============================================================
Param
- t_token *token
- t_shell *data
============================================================
Return
    TRUE : OK
    FALSE: Erorr, prompt ambiguous redirect
    -      stop expansion process & don;t execute
*/

int expand_redir(t_token *token, t_shell *data)
{
    char *temp;
    char *dummy;

    temp = ft_strdup(token->content);
    temp = insert_var(temp, data);

    if (word_count(temp) != 1)
        return (err_msg_3(token->content, ERR_REDIR)
            , free(temp), FALSE);
    
    sub_wild(temp);
    del_quote(temp);
    if (ft_strchr(temp, (char)31))
    {
        if (wild_redir(&dummy, temp))
        {
            free(token->content);
            if (dummy)
            {
                free(temp);
                token->content = dummy;
            }
            else
                token->temp = temp;
        }
        else
            return (err_msg_3(token->content, ERR_REDIR)
            , free(temp), FALSE);
    }
        
}
