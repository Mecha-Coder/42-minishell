/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:42:09 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 14:57:38 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *insert_blank(char *s, int i);
char *insert_exit(char *s, int *i, int code);
char *insert_identifier(char *s, int *i, int len, t_env *env);

/* >>> insert_var
Purpose
- Scan string. When bump into $ dollar, check if meet criteria
- If yes, find the corresponding value and insert inside string        
===========================================================================
Criteria
- $?            : expand to cmd_exit_no
- $[digit: 1-9] : blank
- $[identifier] : check key=identifier in env, expand to that
                : else blank

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
    int len;
    int detect;
    char *temp;
    char *new;

    (i = 0, detect = ON, temp = NULL, new = NULL);
    while (s && s[i])
    {
       if (!detection(s[i], &detect) && detect != SQ_OFF && s[i] == '$')
       {
            if (s[i + 1] >= '1' && s[i + 1] <= '9')   temp = insert_blank(s, i);
            else if (s[i + 1] == '?')                 temp = insert_exit(s, &i, data->cmd_exit_no);
            else if (is_identifier(&s[i + 1], &len))   temp = insert_identifier(s, &i, len, data->env);
            if (new)
                free (new);
            new = temp;
       }
        else
            i++;
    }
    return (new);
}

char *insert_blank(char *s, int i)
{
    s[i] = '\0';
    return (join3(s, NULL, &s[i + 2]));
}

char *insert_exit(char *s, int *i, int code)
{
    char buffer[3];
    char *result;
    
    s[*i] = '\0';
    exit_2_str(buffer, code);
    result = join3(s, buffer, &s[*i + 2]);
    *i += ft_strlen(buffer);
    return (result);
    
}

char *insert_identifier(char *s, int *i, int len, t_env *env)
{
    char *key;
    char *value;
    char *result;

    s[*i] = '\0';
    key = (char *)malloc(len + 1);
    if (!key)
    {
        perror("Malloc fail");
        exit (EXIT_FAILURE);
    }
    ft_strncpy(key, &s[*i + 1], len);
    value = env_val(key, env);
    result = join3(s, value, &s[*i + len + 1]);
    *i += ft_strlen(value);
    free(key);
    return (result);
}

/* Test */

void answer(char *s, t_shell *data)
{
    printf("Input: %s", s);
    insert_var(s, data);
    printf("Output: %s", s);
    printf("\n----------------------------\n\n");
}

int main()
{
    t_shell data;

    t_env n1;
    n1.key = "USER";
    n1.val = "jc";
    n1.next = NULL;

    data.env = &n1;
    data.cmd_exit_no = 127;

    printf("\n");
    char s1[] = "Exit is $?";     
    char s2[] = "User$USER@42kl";    
    char s3[] = "$12345";  
    char s4[] = "$$!lo$a:User"; 
    char s5[] = "##$500";
    char s6[] = "Try expand '$USER'";

    answer(s1, &data);
    answer(s2, &data);
    answer(s3, &data);
    answer(s4, &data);
    answer(s5, &data);
    answer(s6, &data);
}
