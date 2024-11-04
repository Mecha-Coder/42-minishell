/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:08:25 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:25 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == ref)
			return (TRUE);
		temp++;
	}
	return (FALSE);
}

void	free_list(t_node **lst)
{
	t_node	*temp;
	t_node	*current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current->str);
		free(current);
		current = temp;
	}
	(*lst) = NULL;
}
