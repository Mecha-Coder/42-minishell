/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 11:13:54 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_pair	*pair_array(t_token *current);
static void		find_pair(t_token *current, t_pair *pair);

/* >>> check_subshell
Purpose: Check  subshell operator pair meet rule

======================================================================
Note:
-      echo nice && ((echo hi) && (ls)) && (ls && (ls && (ls)))

- Can have multiple subshell in a command
- Can have multiple layers of subshell within subshell (nested bracket)

======================================================================
Method
- Count no. of OB token
- Malloc t_pair struct array
- Store OB and CB pair in the array
- Then loop and check pair if meet rule  

====================================================================
Return
  TRUE  : All shell operator meeting rule
  FALSE : vice versa
*/
int	check_subshell(t_shell *data)
{
	t_pair	*pair;

	pair = pair_array(data->token);
	if (!pair)
		return (TRUE);
	find_pair(data->token, pair);
	if (check_pair(pair, data->input))
		return (free(pair), TRUE);
	return (free(pair), FALSE);
}

/*
- Count no of OB (bracket pairs present)
- Allocate the pair array
- Return NULL if no bracket found
*/
static t_pair	*pair_array(t_token *current)
{
	int		count;
	t_pair	*new;

	(count = 0, new = NULL);
	while (current)
	{
		if (current->type == OB)
			count++;
		current = current->next;
	}
	if (count)
	{
		new = (t_pair *)malloc(sizeof(t_pair) * (count + 1));
		if (!new)
			err_exit("malloc", errno);
		ft_memset(new, 0, sizeof(t_pair) * (count + 1));
	}
	return (new);
}

/*
- finds and group bracket pair in a struct
*/
static void	find_pair(t_token *current, t_pair *pair)
{
	int	i;

	i = 0;
	while (current)
	{
		if (current->type == OB)
		{
			while (pair[i].ob)
				i++;
			pair[i].ob = current;
		}
		if (current->type == CB)
		{
			while (pair[i].cb)
				i--;
			pair[i].cb = current;
		}
		current = current->next;
	}
}
