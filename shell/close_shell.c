/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:10:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 19:22:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_shell(int code, t_shell *data)
{
	if (data->input)
		free(data->input);
	destroy_env(data);
	destroy_tree(data->tree);
	rl_clear_history();
	exit(code);
}
