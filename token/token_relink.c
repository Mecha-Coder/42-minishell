/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_relink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:51:03 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/27 19:51:03 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* token_relink
Purpose: Insert new token group in current token location 
1) Disconnect current and link up new token group to original token list
2) Delete current token
3) Return last new token to continue next
=================================================================
Illustration

-        DEL 
X->X->X   X    X->X  
-     |->X->X->|   <-----NEW GROUP
-           ^
-         RETURN LAST
=================================================================
Param
- t_token *current
- t_token *new
=================================================================
Return 
t_token
	- last new token
*/

t_token	*token_relink(t_token *current, t_token *new)
{
	if (current->prev)
		current->prev->next = new;
	new->prev = current->prev;
	new = token_jumpfront(new);
	if (current->next)
		current->next->prev = new;
	new->next = current->next;
	free(current->content);
	free(current);
	return (new);
}

/*
void init_token(t_token **head, t_token **new)
{
	*head = create_token(STR, ft_strdup("1-Hello"), 0, NULL);
	t_token *current1 = *head;

	current1 = create_token(STR, ft_strdup("2-there"), 0, current1);
	current1 = create_token(STR, ft_strdup("3-I'm"), 0, current1);
	current1 = create_token(STR, ft_strdup("4-testing"), 0, current1);
	current1 = create_token(STR, ft_strdup("5-relink"), 0, current1);

	*new = create_token(STR, ft_strdup("A"), 0, NULL);
	t_token *current2 = *new;

	current2 = create_token(STR, ft_strdup("B"), 0, current2);
	current2 = create_token(STR, ft_strdup("C"), 0, current2);
}

void init_token_new(t_token **new)
{
	*new = create_token(STR, ft_strdup("A"), 0, NULL);
	t_token *current2 = *new;

	current2 = create_token(STR, ft_strdup("B"), 0, current2);
	current2 = create_token(STR, ft_strdup("C"), 0, current2);
}

void view_content(t_token *current, int rev)
{
	if (rev)
		current = token_jumpfront(current);
	while (rev && current)
	{
		printf(" %s |", current->content);
		current = current->prev;
	}
	while(!rev && current)
	{
		printf(" %s |", current->content);
		current = current->next;
	}
}

int main()
{
	t_token *head;
	t_token *new;
	
	init_token(&head, &new);
	head = token_relink(head, new);
	head = token_jumpback(head);
	view_content(head, FALSE);
	printf("\n\n");
	view_content(head, TRUE);   
	destroy_token(head);

	printf("\n-----------------------------\n");

	init_token(&head, &new);
	head = token_jumpfront(head);
	head = token_relink(head, new);
	head = token_jumpback(head);
	view_content(head, FALSE);
	 printf("\n\n");
	view_content(head, TRUE);   
	destroy_token(head);

	printf("\n-----------------------------\n");

	init_token(&head, &new);
	head = head->next->next;
	head = token_relink(head, new);
	head = token_jumpback(head);
	view_content(head, FALSE);
	printf("\n\n");
	view_content(head, TRUE);   
	destroy_token(head);

	printf("\n-----------------------------\n");

	head = create_token(STR, ft_strdup("Only"), 0, NULL);
	init_token_new(&new);
	head = token_relink(head, new);
	head = token_jumpback(head);
	view_content(head, FALSE);
	printf("\n\n");
	view_content(head, TRUE);   
	destroy_token(head);

	printf("\n-----------------------------\n");

	head = create_token(STR, ft_strdup("Only"), 0, NULL);
	new = create_token(STR, ft_strdup("This"), 0, NULL);
	head = token_relink(head, new);
	head = token_jumpback(head);
	view_content(head, FALSE);
	printf("\n\n");
	view_content(head, TRUE);   
	destroy_token(head);

	 printf("\n-----------------------------\n");
}
*/