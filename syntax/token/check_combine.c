/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_combine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:11:41 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/20 16:11:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int left_rule(t_token *left);
int right_rule(t_token *right);

/* >>> check_combine
Purpose: Check combine operator left & right token is a command
=================================================================
Rule

-   (echo Hello || ls) && echo there  

Left side : <CB>, <STR>
Right side: <OB>, <STR>
====================================================================
Return
  TRUE  : All combine operator meeting left and right rule
  FALSE : vice versa
*/

int check_combine(t_shell *data)
{
    t_token *current;

    current = data->token;
    while (current)
    {
        if (current->type >= 1 && current->type <= 3
            && (!left_rule(current->prev) || !right_rule(current->next)))
        {
            err_msg_syntax(data->input, "misuse of combine operator"
                , current->index);
            return (FALSE);
        }
        current = current->next;
    }
    return (TRUE);
}

int left_rule(t_token *left)
{
    if (left && (left->type == CB || left->type == STR))
        return (TRUE);
    return (FALSE);
}

int right_rule(t_token *right)
{
    if (right && (right->type == OB || right->type == STR))
        return (TRUE);
    return (FALSE);
}

/*
void answer(char *s)
{
    t_shell data;

    data.input = s;
    tokenize(&data);
    if (check_combine(&data))
        printf("%s\nOK\n",data.input);
    printf("\n---------------------------\n");
    destroy_token(data.token);
}

int main()
{
    char s1[] = "cat < in.txt && ls";
    char s2[] = "echo bonjour out &&";
    char s3[] = "|| out1.txt cat > out.txt < in.txt";
    char s4[] = "(>> out1.txt cat) && cat < in.txt";
    char s5[] = "(>> out1.txt cat &&) cat < in.txt";
    char s6[] = ">> out1.txt cat (&& cat < in.txt)";
    char s7[] = ">> out1.txt cat || (cat < in.txt)";
    char s8[] = ">> out1.txt cat || << EOF cat < in.txt";

    answer(s1);
    answer(s2);
    answer(s3);
    answer(s4);
    answer(s5);
    answer(s6);
    answer(s7);
    answer(s8);
}
*/