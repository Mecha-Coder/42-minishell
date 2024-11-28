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

void show_err(t_token *token);

/* >>> expand_redir
Purpose: If token is redirect, expand accordingly

============================================================
Steps to expand redirect

1) Expand variable
2) Perform word count, error if != 1
3) Expand wildcard
    return FALSE : Found > 1 matching file, error
    return TRUE  : Found 1 or no matching file
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
    sub_wild(temp, TRUE);
    if (word_count(temp) != 1)
        return (show_err(token), free(temp), FALSE);
    del_quote(temp);
    if (wild_redir(&dummy, temp))
    {
        free(token->content);
        if (dummy)
        {
            free(temp);
            token->content = dummy;
        }
        else
        {
            sub_wild(temp, FALSE);
            token->content = temp;
        }
        return (TRUE);
    }
    return (show_err(token), free(temp), FALSE);
}

void show_err(t_token *token)
{
    err_msg_3(token->content, "ambiguous redirect");
}

/* Test
void answer(char *s)
{
    t_env n1;
    t_env n2;
    t_env n3;
    t_token token;
    t_shell data;

    token.content = ft_strdup(s);

    n1.key = "key1";
    n1.val = "*";
    n1.next = &n2;

    n2.key = "key2";
    n2.val = "d'm*";
    n2.next = &n3 ;

    n3.key = "key3";
    n3.val = "hello there";
    n3.next = NULL;

    data.env = &n1;
    printf("Input : %s\n", token.content);
    if (expand_redir(&token, &data))
        printf("Output: %s\n",token.content);
    free(token.content);
    printf("\n\n------------------------\n");
}

int main()
{
    printf ("\n\n====== MATCH =========\n");
    answer("$key2");
    answer("hello.txt$sosej");
    answer("*logx");
    answer("filename");
    answer("*um*2*");

    printf ("\n\n====== NO MATCH =========\n");
    char s1[] = "*alogx";
    sub_quote(s1, TRUE);
    answer(s1);
    answer("*tt*");
    char s2[] = "t\"*\"t";
    sub_quote(s2, TRUE);
    answer(s2);

    printf ("\n====== ERROR =========\n");
    answer("dum$key1");
    answer("$key3");
    answer("$someting");
}
*/