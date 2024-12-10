/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:54:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 13:25:16 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* >>> initailize
1) Setup local env (in linked-list)
 
2) Keep original terminal stdin & stdout 
	(Need to reset aftter redirect & execute)

3)cmd_exit_no is 0 (zero) at the beginning

4) Customize local env
		* SHELL: 42-minishell
		* SHLVL: ++previous_value
*/
void	initialize(t_shell *data, char **env)
{
	char	*strnum;
	int		shell_lvl;

	setup_env(data, env);
	data->cmd_exit_no = 0;
	strnum = env_val("SHLVL", data->env);
	shell_lvl = ft_atoi(strnum);
	strnum = ft_itoa(++shell_lvl);
	update_env("SHLVL", strnum, data->env);
	update_env("SHELL", "42-minishell", data->env);
	free(strnum);
	data->input = NULL;
	data->token = NULL;
	data->tree = NULL;
	signal(SIGTSTP, SIG_IGN);
}
