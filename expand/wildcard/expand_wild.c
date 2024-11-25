/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wild_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:28:59 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 14:00:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> exp_wild
Purpose: 
- Match wildcard pattern against files/folders in the current dir.
- Loop each entry, if match -> create a <STR> token.
- Return all accumulated tokens after checking all files/folders

NOTE: Only <STR> token. Wildcard for redirect do @ redirect stage
===========================================================================
Example

Current dir    Pattern: du*m*
==========
dummy.txt <MATCH>
dm.txt 
dump.log  <MATCH>
text.jpg
===========================================================================
Return
- No match   : NULL
- Found match: accumulated token (linked-list head)
                 <STR >  ⇋   <STR>
               dummy.txt    dump.log
*/

t_token *exp_wild_str(char *pattern)
{
    DIR *dir;
    struct dirent *entry;
    t_token *current; 
    
    (current = NULL, dir = opendir("."));
    if (!dir)
    {
        perror("Opendir fail");
        exit(EXIT_FAILURE);
    }
    entry = readdir(dir);
    while (entry)
    {
        if (wildcard_match(entry->d_name, pattern))
            current = create_token(STR, 
                ft_strdup(entry->d_name), 
                0, 
                current);
        entry = readdir(dir);
    }
    closedir(dir);
    current = token_jumpback(current);
    return (current);
}


/* Test
void answer(char *pattern)
{
    t_token *token = exp_wild_str(pattern);
    t_token *current = token;
    printf("\npattern: %s\n\n", pattern);
    if (!current)
    {
        printf("Match not found\n");
        return;
    }
    while (current)
    {
        printf("%s\n", current->content);
        current = current->next;
    }
    destroy_token(token);
    printf("\n------------------------\n");
}

int main()
{
    answer("*");
    answer("**");
    answer("*log");
    answer("*txt");
    answer("du*log");
    answer("tex*");
    answer("*um*");
    answer("du*m*t");
    answer("*du*m");
    answer("*dsad*");
}
*/