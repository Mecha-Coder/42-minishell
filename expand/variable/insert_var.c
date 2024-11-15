/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:42:09 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/15 20:42:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

Note: If not meeting criteria, don't expand, leave it
===========================================================================
Example
            ↓          ↓            ↓             ↓
    Exit is $?     User$USER@42kl    $12345  Hello$a:User
              ↓          ↓          ↓            ↓   
    Exit is 127     Userjc@42kl      2345    Hello:User

Note: 
- After insertion, scan index jump to the value's last character 
- Base on this formula, if value=blank, scan index move back by 1
    
[i = i + strlen(value) - 1]
===========================================================================
Return
- char : expanded string (malloc)
       : NULL if no insertion occur 
*/

char *insert_var(char *s, t_shell *data)
{

}