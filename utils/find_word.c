/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:49:49 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 12:18:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> find_word
Purpose: 
- Find the 1st occurance of a word inside a string
- Modify from strstr(), to ignore detection when inside quote
=====================================================================
Example

    word  : "unn" 
    string: Today is a sunny day
-                       ^
-           01234567890123456789  : return(12)             
=====================================================================
Param
- char *word
- char *s
=====================================================================
Return : The 1st character index of the word 
-int 
    >= 0 : Fond match
      -1 : No match
*/

int find_word(char *s, char *word)
{
    int i;
    int j;
    int detect;

    (i = -1, detect = ON);
    while (s && s[++i])
    {
        j = 0;
        while (!detection(s[i], &detect, FALSE) 
            && detect == ON  && s[i + j] == word[j])
        {
            if (!word[j + 1])
                return (i);
            j++;
        }
    }
    return (-1);
}

/*
void answer(char *s, char *word)
{
    int index;
    int i;

    i = 0;
    index = find_word(s, word);
    
    if (index >= 0)
    {
        while(i++ < index)
		    printf(" ");
	    printf("↓\n");
    }
    else
        printf("Match not found\n");
    printf("%s\n\n---------------------------\n", s);
}

int main()
{
    answer("Today is a sunny day", "unn");
    answer("Today is a sunny day", "day");
    answer("Today is a sunny day", "o");
    answer("Umbrella", "a");
    answer("55", "55");

    answer("565", "55");
    answer("Almost there", "ete");
    answer("Almost there", "At");
}
*/