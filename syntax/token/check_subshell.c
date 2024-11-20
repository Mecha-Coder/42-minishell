/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/20 17:06:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>>check_subshell
Purpose: Check  subshell operator pair meet rule
======================================================================
Note:
-       (echo nice && (ls)) && (echo hi)

- Can have multiple subshell in a command
- Can have multiple layers of subshell within subshell (nested bracket)  
======================================================================
Rule
Outside:
-     <START><COMBINE OPERATOR> ( ) <COMBINE OPERATOR><END>

Inside:
-   (<STR>) OR
-   (<OB>  <!CB>) EITHER (<!OB> <CB>) <--- CHECK REDUNDANT BRACKET (())
======================================================================
Method
Convert token into number array
-START                                                           END
   | <OB><STR><STR><AND><OB><STR><CB><CB><AND><OB><STR><STR><CB> |
-  -1  8   10  10    1   8    10   9  9    1   8    10   10  9   0 

- Scan the 1st group of brackets 
- Start with outmost bracket pair, check above rule
- If available, check inner bracket pairs (do recursively) 
- After done, move forward to validate other bracket groups

====================================================================
Return
  TRUE  : All shell operator meeting rule
  FALSE : vice versa
*/

int check_subshell(t_shell *data)
{
    i = 1
    t_sub *s;

    s = token_array(data->token);

}

t_sub *token_array(t_token *current)
{
    t_sub *new;
    int i;

    i = 0;
    while(current && ++i)
        current = current->next;
    new = (t_sub *)malloc(sizeof(t_sub) * (i + 1));
    if (!new)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    current = token_jumpback(current);
    i = 0;
    while (current)
    {
        new[i++] = (t_sub){current->type, current->index};
        current = current->next;
    }
    new[i] = {0, -1};
    return (new);
}
