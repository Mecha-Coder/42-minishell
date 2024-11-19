/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:11:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 15:51:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> tokenize
Purpose: Create a token representation of the input
==================================================================
Example
    Input     :  cat  < in.txt  &&  ls
    Token list: <STR><RD><STR><AND><STR>
    Type      :   10   5   10   1   10
==================================================================
Method
Input :  cat < in.txt && ls
         123456789012345678

Stage1: Extract operator and replace with space character

    Input      : cat___in.txt____ls
    Token list: <RD><AND>
    Index     :  5   14

Stage2: Extract word with space as delimiter

    Content   :           cat in.txt ls     
    Token list: <RD><AND><STR><STR><STR>
    Index     :  5   14    1    7    17

Stage3: Sort index
==================================================================
Param 
    t_data
*/

void tokenize(t_shell *data)
{
    char *s;
    t_token *operator;
    t_token *word;
    
    s = ft_strdup(data->input);
    operator = extract_operator(s);
    word = extract_word(s);
    data->token = join_token(operator, word);
    free(s);
}