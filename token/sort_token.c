/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:40 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 16:01:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *lowest_token_index(t_token *head);

/* >>> sort_token
Purpose: Sort token based on the index
======================================================================
Extra 
- If input token is not the head. This function will jumpback to 
    head node first before sorting
======================================================================
Method
1) select the token with lowest index from linked list
2) Disconnect selected node
3) Connect to sorted list
======================================================================
Return
- t_token * : sorted by index
*/

t_token *sort_token(t_token *head)
{
    t_token *sorted;
    t_token *select;

    sorted = NULL;
    head = token_jumpback(head);
    while (head)
    {
        select =  lowest_token_index(head);
        if (select->prev)
            select->prev->next = select->next;
        else
            head = select->next;
        if (select->next)
            select->next->prev = select->prev;
        if (sorted)
            sorted->next = select;
        select->prev = sorted;
        select->next = NULL;
        sorted = select;
    }
    sorted = token_jumpback(sorted);
    return (sorted); 
}


t_token *lowest_token_index(t_token *head)
{
    t_token *current;
    t_token *select;

    select = head;
    current = head->next;
    while (current)
    {
        if (current->index < select->index)
            select = current;
        current = current->next;
    }
    return (select);
}

/* Test
void show_result(t_token *sorted, t_token *head)
{
    sorted = token_jumpback(sorted);
    printf("Sorted : "); show_token(sorted, 'H');
    printf("Head   : "); show_token(head, 'H');
    printf("\n---------------------------------\n");
}

int main()
{
    t_token t1;
    t_token t2;
    t_token t3;
    t_token t4;
    t_token t5;
    t_token t6;
    t_token t7;
    t_token t8;
    t_token t9;

    t1.type = CB;
    t1.content = NULL;
    t1.index = 9;
    t1.prev = NULL;
    t1.next = &t2;
    
    t2.type = AND;
    t2.content = NULL;
    t2.index = 13;
    t2.prev = &t1;
    t2.next = &t3;

    t3.type = PIPE;
    t3.content = NULL;
    t3.index = 5;
    t3.prev = &t2;
    t3.next = &t4;

    t4.type = PIPE;
    t4.content = NULL;
    t4.index = 18;
    t4.prev = &t3;
    t4.next = &t5;

    t5.type = HERE;
    t5.content = NULL;
    t5.index = 3;
    t5.prev = &t4;
    t5.next = &t6;

    t6.type = RD;
    t6.content = NULL;
    t6.index = 19;
    t6.prev = &t5;
    t6.next = &t7;

    t7.type = WR;
    t7.content = NULL;
    t7.index = 16;
    t7.prev = &t6;
    t7.next = &t8;

    t8.type = AND;
    t8.content = NULL;
    t8.index = 10;
    t8.prev = &t7;
    t8.next = &t9;

    t9.type = OB;
    t9.content = NULL;
    t9.index = 1;
    t9.prev = &t8;
    t9.next = NULL;

    t_token *current = sort_token(&t1);
    show_token(current, 'I');
}
*/