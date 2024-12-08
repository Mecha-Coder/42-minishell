/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:48:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 12:22:24 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define REDIR_ERR "after redirect must be a word"

/* >>> check_redirect
Purpose: Check redirect token must be followed by word token<STR>
===================================================================
Example
    <WR><STR> OK
    <RD><AND> KO
====================================================================
Return
  TRUE  : All redirect token have word token after that
  FALSE : vice versa
*/

int check_redirect(t_shell *data)
{
    t_token *current;

    current = data->token;
    while (current)
    {
        if (current->type >= 4 && current->type <= 7
            && (!current->next || current->next->type != STR))
        {
            if (current->next)
                err_msg_4(data->input, REDIR_ERR
                    , current->next->index);
            else
                err_msg_4(data->input, REDIR_ERR, current->index);
            return (FALSE);
        }
        current = current->next;
    }
    return (TRUE);
}
/* Test
void answer(char *s)
{
    t_shell data;

    data.input = s;
    tokenize(&data);
    if (check_redirect(&data))
        printf("%s\nOK\n",data.input);
    printf("\n---------------------------\n");
    destroy_token(data.token);
}

int main()
{
    char s1[] = "cat < in.txt && ls";
    answer(s1);
    char s2[] = "echo bonjour > > out";
    answer(s2);
    char s3[] = "> out1.txt cat > out.txt < in.txt";
    answer(s3);
    char s4[] = ">> out1.txt cat > && < in.txt";
    answer(s4);
    char s5[] = "ls out.txt >";
    answer(s5);
    char s6[] = "<<";
    answer(s6);
}
*/


