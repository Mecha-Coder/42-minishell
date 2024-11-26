/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occurance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:35:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 11:04:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int symbol(char c);

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
  TRUE  : Meeting rule
  FALSE : vice versa
*/
int check_occurance(char *s)
{
    int i;
    int j;
    int detect;

    (i = 0, detect = ON);
    while (s && s[i])
    {
        if (!detection(s[i], &detect, FALSE) && detect == ON 
            && (symbol(s[i]) || s[i] == '&'))
        {
            j = 1;
			while (s[i] == s[i + j])
				j++;
            if ((symbol(s[i]) && j > 2) || (s[i] == '&' && j != 2))
            {
                err_msg_4(s, "invalid operator", i);
                return (FALSE);
            }
            i += j;
        }
        else
            i++;
    }
    return (TRUE);
}

int symbol(char c)
{
    return (c == '<' ||c == '>' || c == '|');
}

/*
void answer(char *s)
{
    if (check_occurance(s))
        printf("%s\nOK\n", s);
    printf("\n\n------------------\n");
}

int main()
{
    printf ("\n--> ERROR TEST\n\n");
	answer("echo hello & (echo done)");
	answer("echo bonjour  >>>  test");
	answer("cat XXX || echo ok ||| echo  done");
	answer("ls >>> in.txt");
    answer("bonjour  >>>  test");
    answer("echo '&' & rm file");
    answer("cat eval.h | cat | |cat | ls");
    answer("echo bonjour  >>>  test");
    answer("> out1.txt echo >>>>> out.txt < in.txt");
    answer("touch & file.txt");

    printf ("\n--> OK TEST\n\n");
	answer("(echo 5) > out.txt");
	answer(" ls -l | (grep ic)");
	answer("ls out.txt >");
	answer("cat eval.h | cat | |cat | ls");
	answer("pwd && (mkdir new && cd new) && pwd && rmdir new");
	answer("(echo \"World\" && (echo \"Hello\"))");
	answer("(export a=10 && echo $a) && echo $a");
	answer("pwd && (cd ../ && pwd) && pwd << EOF");
	answer("ls -l && (echo hello && echo nice to meet you)");
	answer("| ls | wc -l > > out.txt");
	answer("env | grep SHLVL && (env | grep SHLVL)");
    answer("cat < <");
    answer("> out1.txt echo \">>>>> out.txt\" < in.txt");
    answer("cat in.txt << EOF > out1.txt >> out2.txt");
    answer("> out1.txt cat > out.txt < in.txt");
    answer("cat < in.txt && ls");
}
*/