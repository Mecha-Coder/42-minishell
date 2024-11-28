/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:22:28 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/27 21:22:28 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token *expand_str_1(t_token *current);
t_token *expand_str_2(t_token *current);
t_token *expand_str_3(t_token *current);

/* >>> expand_str
Purpose: If token is word(STR), expand accordingly
=============================================================
Steps to expand word

1) Expand var
2) Word count
-  0 : free content, content = NULL;
-  1 : do normal
- > 1: extract_word, then do normal
3) Do relink 
============================================================
Param
- t_token *current
- t_shell *data
============================================================
Return
t_token : Updated current token
*/

t_token *expand_str(t_token *current, t_shell *data)
{
    int count;

    current->content = insert_var(current->content, data);
    sub_wild(current->content, TRUE);
    count = word_count(current->content);
    if (count == 0)
        return (expand_str_1(current));
    else if (count > 1)
        return (expand_str_2(current));
    return (expand_str_3(current));
}

t_token *expand_str_1(t_token *current)
{
    free(current->content);
    current->content = NULL;
    return (current);
}


t_token *expand_str_2(t_token *current)
{
    t_token *holder;

    holder = extract_word(current->content);
    while (holder)
    {
        holder = expand_str_3(holder);
        if (holder->next)
            holder = holder->next;
        else
            break;
    }
    holder = token_jumpback(holder);
    return (token_relink(current, holder));
}

/* 
Note: return last new token
*/
t_token *expand_str_3(t_token *current)
{
    t_token *holder;

    del_quote(current->content);
    holder = wild_str(current->content);
    if (holder)
        return (token_relink(current, holder));
    sub_wild(current->content, FALSE);
    return (current);
}

/* Test
void answer(char *s, t_env *env)
{
    t_shell data;
    t_token *current;

    data.input = s;
    data.cmd_exit_no = 0;
    data.env = env;
    tokenize(&data);
    merge_redirect(data.token);
    current = data.token;
    printf("Before\n");
    show_token(data.token, 'C');
    while (current)
    {
        sub_quote(current->content, TRUE);
        if (current->type == STR)
            current = expand_str(current, &data);
        if (current->next)
            current = current->next;
        else
            break;
    }
    data.token = token_jumpback(current);
    printf("After\n");
    show_token(data.token, 'C');
    destroy_token(data.token);
    printf("\n\n----------------------------\n");
}

int main()
{
    t_env n1;
    t_env n2;
    t_env n3;

    n1.key = "a";
    n1.val = "hi       there      $SHELL      *";
    n1.next = &n2;

    n2.key = "h";
    n2.val = "o  a\"b\"c";
    n2.next = &n3;

    n3.key = "q";
    n3.val = "*   \"*\"  *   *";
    n3.next = NULL;

    char s1[] = "$qwe << EOF";
    char s2[] = "echo *";
    char s3[] = "e'c'ho a\"b\"c";
    char s4[] = "echo \"dumm\"*";
    char s5[] = "echo \"dumm*\"";
    char s6[] = "$d $h d*m";
    char s7[] = "ec$a";
    char s8[] = "ec\"$a\" > file/out 'Nice       day' >> file/ou1 $h";
    char s9[] = "ec'$a'";
    char s10[] = "###$a#Hello$?";
    char s11[] = "\"###$a#Hello\"";
    char s12[] = "$a";
    char s13[] = "\"$a\"";
    char s14[] = "e'c'h$h";
    char s15[] = "e'c'h\"$h\"";
    char s16[] = "echo hel\"$a\"";
    char s17[] = "echo hel$a";

    answer(s1,&n1);
    answer(s2,&n1);
    answer(s3,&n1);
    answer(s4,&n1);
    answer(s5,&n1);
    answer(s6,&n1);
    answer(s7,&n1);
    answer(s8,&n1);
    answer(s9,&n1);
    answer(s10,&n1);
    answer(s11,&n1);
    answer(s12,&n1);
    answer(s13,&n1);
    answer(s14,&n1);
    answer(s15,&n1);
    answer(s16,&n1);
    answer(s17,&n1);
}
*/
