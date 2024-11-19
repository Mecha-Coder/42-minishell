/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:12:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:06:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_alphabet(char c);
int is_alnumeric(char c);

/* >>> is_identifier
Purpose: Check the first sub-string is an identifier
====================================================================
RULE
1) First letter must be alphabet
2) Can be followed by other alphanumeric letters

alphanumeric = alphabet + digit
alphabet = [_][a-z][A-Z]
digital  = [0-9]
====================================================================
Example: 

_Hello#55 : return (6)
@dash     : return (0)
ab_5      : return (4)
====================================================================
Param
- char *s : String that may contain identifier
- int *i  : Reference pointer to store len of identifier found
====================================================================
Return:
- int
    0   : No identifier found
    0 > : Lenght of the identifer found
====================================================================
Side effect
- Update (int *i) with *i=strlen(identifier) to be used by parent
- *i is equal to the return value
*/

int is_identifier(char *s, int *i)
{
    *i = 0;
    if (!is_alphabet(s[*i]))
        return (*i);
    while(s[++(*i)])
    {
        if (!is_alnumeric(s[*i]))
            return (*i);
    }
    return (*i);
}

int is_alphabet(char c) 
{
    return (ft_isalpha(c) || (c == '_'));
}

int is_alnumeric(char c) 
{
    return (is_alphabet(c) || ft_isdigit(c));
}



/* Test

int main() 
{   
    int i;
    printf("\n[OK]\n");
    printf("%4d : %s\n", is_identifier("hello_world1", &i), "hello_world1");
    printf("%4d : %s\n", is_identifier("varName", &i), "varName");
    printf("%4d : %s\n", is_identifier("_underscore", &i), "_underscore");
    printf("%4d : %s\n", is_identifier("item1", &i), "item1");
    printf("%4d : %s\n", is_identifier("longVariableNameWithMixedCase", &i)
    , "longVariableNameWithMixedCase");
    printf("%4d : %s\n", is_identifier("MAX_VALUE", &i), "MAX_VALUE");
    printf("%4d : %s\n", is_identifier("a", &i), "a");
    printf("%4d : %s\n", is_identifier("_2fast", &i), "_2fast");
    printf("%4d : %s\n", is_identifier("data123", &i), "data123");
    printf("%4d : %s\n", is_identifier("record_", &i), "record_");
    printf("%4d : %s\n", is_identifier("__init__", &i), "__init__");


    printf("\n\n[K0]\n");
    printf("%4d : %s\n", is_identifier("42_not_valid", &i), "42_not_valid");
    printf("%4d : %s\n", is_identifier("123item", &i), "123item");
    printf("%4d : %s\n", is_identifier("variable-name", &i)
    , "variable-name");
    printf("%4d : %s\n", is_identifier("float*", &i), "float*");
    printf("%4d : %s\n", is_identifier("my var", &i), "my var");
    printf("%4d : %s\n", is_identifier("@user", &i), "@user");
    printf("%4d : %s\n", is_identifier("while$", &i), "while$");
    printf("%4d : %s\n", is_identifier("char", &i), "char");
    printf("%4d : %s\n", is_identifier("name#", &i), "name#");

    return 0;
}
*/