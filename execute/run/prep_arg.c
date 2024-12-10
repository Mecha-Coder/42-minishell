/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:40:29 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/30 15:40:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_arg(t_token *current);

/* >>> prep_arg
Purpose: Convert command inside tokens into 2D array

=========================================================
Return
- char ** : command in array {"wc", "-l", NULL}
		  : NULL if no command (type=STR && content)
*/

char	**prep_arg(t_token *current)
{
	char	**args;
	int		i;

	i = count_arg(current);
	if (i == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (i + 1));
	if (!args)
		err_exit("malloc", errno);
	i = 0;
	while (current)
	{
		if (current->type == STR && current->content)
			args[i++] = current->content;
		current = current->next;
	}
	args[i] = NULL;
	return (args);
}

static int	count_arg(t_token *current)
{
	int	size;

	size = 0;
	while (current)
	{
		if (current->type == STR && current->content)
			size++;
		current = current->next;
	}
	return (size);
}

/*
int main()
{
	t_token t1;
	t_token t2;
	t_token t3;
	t_token t4;
	t_token t5;
	t_token t6;
	t_token t7;

	t1.type = STR;
	t1.content = "Helo";
	t1.prev = NULL;
	t1.next = &t2;

	t2.type = STR;
	t2. content = NULL;
	t2.prev = NULL;
	t2.next = &t3;

	t3.type = WR;
	t3.content = "output.txt";
	t3.prev = NULL;
	t3.next = &t4;

	t4.type = STR;
	t4.content = "\"Super Saiyan\"";
	t4.prev = NULL;
	t4.next = &t5;

	t5.type = RD;
	t5.content = "filename";
	t5.prev = NULL;
	t5.next = &t6;

	t6.type = STR;
	t6.content = "Goku";
	t6.prev = NULL;
	t6.next = &t7;

	t7.type = STR;
	t7.content = "";
	t7.prev = NULL;
	t7.next = NULL;

	int i = -1;
	char **arg = prep_arg(&t1);
	while (arg[++i])
		printf("%d) [%s]\n", i, arg[i]);
	free(arg);
}
*/