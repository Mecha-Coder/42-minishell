/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 08:58:19 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_pair *pair_array(t_token *current);
void find_pair(t_token *current, t_pair *pair);

/* >>> check_subshell
Purpose: Check  subshell operator pair meet rule

======================================================================
Note:
-      echo nice && ((echo hi) && (ls)) && (ls && (ls && (ls)))

- Can have multiple subshell in a command
- Can have multiple layers of subshell within subshell (nested bracket)

======================================================================
Method
- Count no. of OB token
- Malloc t_pair struct array
- Store OB and CB pair in the array
- Then loop and check pair if meet rule  

====================================================================
Return
  TRUE  : All shell operator meeting rule
  FALSE : vice versa
*/
int check_subshell(t_shell *data)
{
    t_pair *pair;

    pair = pair_array(data->token);
    if (!pair)
        return (TRUE);
    find_pair(data->token, pair);
    if (check_pair(pair, data->input))
        return (free(pair), TRUE);
    return (free(pair), FALSE);

}

/*
- Count no of OB (bracket pairs present)
- Allocate the pair array
- Return NULL if no bracket found
*/
t_pair *pair_array(t_token *current)
{
    int count;
    t_pair *new;

    (count = 0, new = NULL);
    while (current)
    {
        if (current->type == OB)
            count++;
        current = current->next;
    }
    if (count)
    {
        new = (t_pair *)malloc(sizeof(t_pair) * (count + 1));
        if (!new)
        {
            perror("Malloc fail");
            exit(EXIT_FAILURE);
        }
        ft_memset(new, 0 , sizeof(t_pair) * (count + 1));
    }
    return (new);
}

/*
- finds and group bracket pair in a struct
*/
void find_pair(t_token *current, t_pair *pair)
{
    int i;
    
    i = 0;
    while(current)
    {
        if (current->type == OB)
        {
            while (pair[i].ob)
                i++;
            pair[i].ob = current;
        }
        if (current->type == CB)
        {
            while (pair[i].cb)
                i--;
            pair[i].cb = current;
        }
        current = current->next;
    }
}

/*
void answer(char *s)
{
    t_shell data;

    data.input = s;
    tokenize(&data);
    if (check_subshell(&data))
        printf("%s\nOK\n", data.input);
    printf("---------------------------\n\n");
    destroy_token(data.token);
}

int main()
{
    char s0[] = "echo lo && (echo nice && (ls)) && ((echo hi) && (ls) && (ls)) && (ls && (ls && (ls)))";   
    char s1[] = "echo hello && (echo hi && (echo good && echo day))";
    char s2[] = "(echo nice && (ls)) && echo hi";
    char s3[] = " echo hello && (echo hi && (echo hello && echo good) && echo day)";
    char s4[] = "echo hello && (echo) && echo hi";
    char s5[] = "echo hello && (echo nice && ls) && echo hi";
    char s6[] = "echo hello && (echo nice && (ls)) && echo hi ";
    char s7[] = "(echo hello)";
    char s8[] = "(ls)";
    char s9[] = "echo hello && (echo hi && (echo good && echo day))";
    char s10[] = "ls && (ls && (ls && (ls && (ls && (ls && (ls)))))) && ls";
    char s11[] = "(echo hi) || echo hi && (echo hello)";
    char s12[] = "(ls) && echo hello";
    char s13[] = "(echo hello) && ls";
    char s14[] = "((echo hello) && (ls))";

    char s15[] = "() && echo done ()";
    char s16[] = "() && (                   )";
    char s17[] = "()";
    char s18[] = "(echo 5) > out.txt";
    char s19[] = "(echo 5) 6";
    char s20[] = "echo hello && (echo hi && (echo hello (echo good) && echo day))";
    char s21[] = "echo hello && (echo hi && (echo (good) && echo day))";
    char s22[] = "(echo nice && ((ls))) && echo hi";
    char s23[] = "((echo nice && (ls))) && echo hi";
    char s24[] = "ls && (ls && (ls && (ls && (ls && (ls && ((ls))))))) && ls";
    char s25[] = "ls && (ls && (ls && (ls && ((ls && (ls && (ls))))))) && ls";
    char s26[] = "echo hello | (cat) ";
    char s27[] = "((echo hello))";
    char s28[] = "echo hello && (echo (nice)) && echo hi";
    char s29[] = "echo hello && () && echo hi";
    char s30[] = "echo hello && (echo nice (ls)) && echo hi";
    char s31[] = "echo hello && ((echo nice && (ls))) && echo hi";
    char s32[] = "(echo hi) || echo hi && (echo (hello))";
    char s33[] = "(echo hi) (echo hello)";
    char s34[] = "(<< EOF (echo) hi) ";
    char s35[] = "ls && >> outside.txt (echo hi)";
    char s36[] = "ls && echo hi";
    
    answer(s0);
    answer(s1);
    answer(s2);
    answer(s3);
    answer(s4);
    answer(s5);
    answer(s6);
    answer(s7);
    answer(s8);
    answer(s9);
    answer(s10);
    answer(s11);
    answer(s12);
    answer(s13);
    answer(s14);
    answer(s15);
    answer(s16);
    answer(s17);
    answer(s18);
    answer(s19);
    answer(s20);
    answer(s21);
    answer(s22);
    answer(s23);
    answer(s24);
    answer(s25);
    answer(s26);
    answer(s27);
    answer(s28);
    answer(s29);
    answer(s30);
    answer(s31);
    answer(s32);
    answer(s33);
    answer(s34);
    answer(s35);
    answer(s36);
}
*/