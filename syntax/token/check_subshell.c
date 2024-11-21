/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/21 12:58:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int eval_subshell(t_sub *sub, char *input);

/* >>> check_subshell
Purpose: Check  subshell operator pair meet rule

======================================================================
Note:
-       (echo nice && (ls)) && (echo hi)

- Can have multiple subshell in a command
- Can have multiple layers of subshell within subshell (nested bracket)
======================================================================
Method
Convert token into array of struct
-    START                                                      END
   | <OB><STR><STR><AND><OB><STR><CB><CB><AND><OB><STR><STR><CB> 0

- Find the 1st group of brackets 
- Start with outmost bracket pair, check pair with rule
- If available, check inner bracket pairs (do recursively) 
- After done, move forward to validate other bracket groups

====================================================================
Return
  TRUE  : All shell operator meeting rule
  FALSE : vice versa
*/
int check_subshell(t_shell *data)
{
    int ob;
    int cb;
    t_sub *sub;
    t_sub *trim;

   sub = token_array(data->token);
   trim = sub;
   while (find_pair(trim, &ob, &cb))
   {
        if (!eval_subshell(trim, data->input))
            return (free(sub), FALSE);
        trim = &trim[cb + 1];
   }
   return (free(sub), TRUE);
}

int eval_subshell(t_sub *sub, char *input)
{
    int ob;
    int cb;

    if (find_pair(sub, &ob, &cb))
    {
        if (!check_pair(sub, ob, cb, input))
            return (FALSE);
        return (eval_subshell(&sub[ob + 1], input));
    }
    return (TRUE);
}

int asnwer(char *s)
{
    t_shell data;

    data.input = s;
    tokenize(&data);
    check_subshell(&data);
    destroy_token(data.token);
}

int main()
{
    printf("============= Correct syntax ==============");
    
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

    printf("============= Wrong syntax ==============");

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
}