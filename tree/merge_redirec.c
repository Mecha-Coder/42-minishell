/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_redirec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:47:01 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/22 13:36:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> merge_redirect
Purpose: Prep for building AST. Can merge <REDIRECT><STR>
*/

void merge_redirect(t_token *current)
{
    t_token *release;

    while (current)
    {
        if (current->type >= 4 && current->type <= 7)
        {
            release = current->next;
            current->content = release->content;
            current->next = release->next;
            if (release->next)
                release->next->prev = current;
            free(release);
        }
        current = current->next;
    }
}


/* Test
void answer(char *s)
{
    t_shell data;

    data.input = s;
    tokenize(&data);
    printf("Before: "); show_token(data.token, 'H');
    merge_redirect(data.token);
    printf("After : "); show_token(data.token, 'H');
    printf("\n---------------------------\n");
    destroy_token(data.token);
}

int main()
{
    char s1[] = "cat < in.txt && ls";
    answer(s1);
    char s3[] = "> out1.txt cat > out.txt < in.txt";
    answer(s3);
}
*/