/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occurance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:35:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/18 21:35:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int symbol(char c);
int occur_type1(char *s, int *i);
int occur_type2(char *s, int *i);

/* >>> check_occurance
Purpose: Check operator symbol consecutive occurance meet below rule.
=======================================================================
Rule
operator occur  <= 2 
    < , <<  
	> , >> 
	| , ||
operator occur == 2
	&&
=======================================================================
Return
  TRUE  : All bracket have pair
  FALSE : vice versa
*/
int check_occurance(char *s)
{
    int i;
    int detect;

    (i = 0, detect = ON);
    while (s && s[i])
    {
        detection(s[i], &detect);
        if (detect == ON && symbol(s[i]) && !occur_type1(s, &i))
            return (FALSE);
        else if (detect == ON && s[i] == '&' && !occur_type2(s, &i))
            return (FALSE);
        else
            i++;
    }
    return (TRUE);
}

int symbol(char c)
{
    return (c == '<' ||c == '>' || c == '|');
}

int occur_type1(char *s, int *i)
{
    int j;

    j = 1;
    if (s[*i + 1] == s[*i] && ++j 
        && s[*i + 2] == s[*i])
    {
        err_msg_syntax(s, "invalid operator", *i);
        return (FALSE);
    }
    *i = j;
    return (TRUE);
}

int occur_type2(char *s, int *i)
{
    if (s[*i + 1] == s[*i] 
        && s[*i + 2] != s[*i])
    {
       *i = 2;
       return (TRUE);
    }
    err_msg_syntax(s, "invalid operator", *i);
    return (FALSE);
}

void answer(char *s)
{
    if (check_occurance(s))
        printf("%s\nOK\n", s);
    printf("\n\n------------------\n");
}

int main()
{
    answer("bonjour  >>>  test");
    answer("echo '&' & rm file");
    answer("cat eval.h | cat | |cat | ls");
    answer("echo bonjour  >>>  test");
    answer("> out1.txt echo >>>>> out.txt < in.txt");
    answer("touch & file.txt");

    answer("cat < <");
    answer("> out1.txt echo \">>>>> out.txt\" < in.txt");
    answer("cat in.txt << EOF > out1.txt >> out2.txt");
    answer("> out1.txt cat > out.txt < in.txt");
    answer("cat < in.txt && ls");
}