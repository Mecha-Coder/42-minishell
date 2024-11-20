/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:36:57 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 15:52:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void initialize_words(char words[][3]);
void sub_to_space(char *s, int i, int size);

/* >>> extract_operator
Purpose: 
- Find operator in input and create token
- Then, replace operator found with "space" character
==============================================================
Return 
- token *operator
- NULL, if no operator found
*/

t_token *extract_operator(char *s)
{
    int i;
    int index;
    char opt_list[11][3];
    t_token *operator;

    (i = 1, operator = NULL);
    initialize_words(opt_list);
    while (opt_list[i][0])
    {
        index = find_word(s, opt_list[i]);
        if (index >= 0)
        {
            operator = create_token(i, NULL, index, operator);
            sub_to_space(s, index, ft_strlen(opt_list[i]));
        }
        else
            i++;
    }
    return (token_jumpback(operator));
}

void initialize_words(char words[][3])
{
    ft_strcpy(words[AND], "&&");
    ft_strcpy(words[OR], "||");
    ft_strcpy(words[PIPE], "|");
    ft_strcpy(words[HERE], "<<");
    ft_strcpy(words[RD], "<");
    ft_strcpy(words[APPD], ">>");
    ft_strcpy(words[WR], ">");
    ft_strcpy(words[OB], "(");
    ft_strcpy(words[CB], ")");
    words[10][0] = '\0';
}

void sub_to_space(char *s, int i, int size)
{
    while (size--)
        s[i++] = ' ';
}

/* Test

void answer(char *s)
{
    t_token *operator = extract_operator(s);
    show_token(operator, 'D');
    printf("[%s]\n", s);
    destroy_token(operator);
    printf("\n--------------------------\n");
}

int main()
{
    char s1[] = "&& cat < in.txt && ls |";
    answer(s1);
    char s2[] = "Hello there" ;
    answer(s2);
    char s3[] = "export TEST=Yoyo && echo $TEST | tr a-z A-Z";
    answer(s3);
    char s4[] = "(echo hI && echo done) | tr a-z A-Z | wc -l";
    answer(s4);
    char s5[] = "rm non_existent_file ||  echo \"Exit staus: $?\" && echo \"Exit staus: $?\"";
    answer(s5);
    char s6[] = "echo 'Hello   '\"there\"";
    answer(s6);
    char s7[] = "cat < <";
    answer(s7);
    char s8[] = "> out1.txt echo \">>>>> && out.txt\" < in.txt '|'";
    answer(s8);
    char s9[] = ">";
    answer(s9);
}
*/

