/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:42:09 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 20:00:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *insert_blank(char *s, int i);
static char *insert_minishell(char *s, int i);
static char *do_insertion(char *s, int *i, t_shell *data);

/* >>> insert_var
Purpose
- Scan string. When bump into $ dollar, check if meet criteria
- If yes, find the corresponding value and insert inside string        
===========================================================================
Criteria
- $?                     : expand to cmd_exit_no
- $[digit: 1-9] $[@] $[!]: blank
- $[identifier]          : check key=identifier in env, expand to that
                         : else blank
- $0                     : minishell

Note: 
- If not meeting criteria, don't expand, leave it
- Don't check when inside 'single quote'
===========================================================================
Example
            ↓          ↓             ↓            ↓           ↓
    Exit is $?     User$USER@42kl    $12345  $$!lo$a:User   ##$500
               ↓          ↓          ↓            ↓           ↓
    Exit is 127     Userjc@42kl      2345    $$!lo:User     ##00

Note: 
- After insertion, scan index jump to the value's last character + 1

[i = i + strlen(value)]
===========================================================================
Return
- char : expanded string (malloc)
       : NULL if no insertion occur 
*/

char *insert_var(char *s, t_shell *data)
{
    int i;
    int detect;
    char *temp;

    (i = 0, detect = ON);
    while (s && s[i])
    {
        if (!detection(s[i], &detect, TRUE) && detect != SQ_OFF && s[i] == '$')
        {
            temp = do_insertion(s, &i, data);
            if (temp)
            {
                free (s);
                s = temp;
                continue;
            }
        }
        i++;
    }
    return (s);
}

static char *do_insertion(char *s, int *i, t_shell *data)
{
    int len;

    if ((s[*i + 1] >= '1' && s[*i + 1] <= '9') 
        || s[*i + 1] == '@'
        || s[*i + 1] == '!')     
        return (insert_blank(s, *i));

    else if (s[*i + 1] == '0')
        return (insert_minishell(s, *i)) ;

    else if (s[*i + 1] == '?')                    
        return (insert_exit(s, i, data->cmd_exit_no));

    else if (is_identifier(&s[*i + 1], &len))     
        return (insert_value(s, i, len, data->env));
        
    return (NULL);
}

static char *insert_blank(char *s, int i)
{
    s[i] = '\0';
    return (join3(s, NULL, &s[i + 2]));
}

static char *insert_minishell(char *s, int i)
{
    s[i] = '\0';
    return (join3(s, "_42_minishell", &s[i + 2]));
}


/* Test
void answer(char *s, t_shell *data)
{
    char *input;
    char *output;

    input = (char *)malloc(ft_strlen(s) + 1);
    ft_strcpy(input, s);
    
    printf("Input : %s\n", input);
    sub_quote(input, TRUE);
    output = insert_var(input, data);
    del_quote(output);
    printf("Output: %s\n", output);
    printf("\n----------------------------\n\n");
    free(output);
}

int main()
{
    t_shell data;

    t_env n1;
    t_env n2;

    n1.key = "USER";
    n1.val = "jc is awesome";
    n1.next = &n2;

    n2.key = "a";
    n2.val = "\"Nice\"";
    n2.next = NULL;

    data.env = &n1;
    data.cmd_exit_no = 127;

    printf("\n");
    char s1[] = "Exit is $?'$?'";     
    char s2[] = "User$USER@42kl";    
    char s3[] = "$12345";  
    char s4[] = "$$!lo$a:User"; 
    char s5[] = "##$500";
    char s6[] = "Try expand '$USER'";
    char s7[] = "$USER\"$USER#right\"'$USER'";
    char s8[] = "$$!lo\"$a\":User";
    char s9[] = "$$!lo'$a':User";
    char s10[] = "$Something'$Done:'";
    char s11[] = "$hh";
    char s12[] = "ec$a\"a\"";
    char s13[] = "'Hello*'*";

    answer(s1, &data);
    answer(s2, &data);
    answer(s3, &data);
    answer(s4, &data);
    answer(s5, &data);
    answer(s6, &data);
    answer(s7, &data);
    answer(s8, &data);
    answer(s9, &data);
    answer(s10, &data);
    answer(s11, &data);
    answer(s12, &data);
    answer(s13, &data);
}
*/



