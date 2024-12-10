/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:50:39 by jetan             #+#    #+#             */
/*   Updated: 2024/12/10 14:50:39 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern int	g_sig;

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include "struct.h"
#include "constant.h"
#include "utils.h"
#include "expand.h"
#include "built_in.h"
#include "env.h"
#include "token.h"
#include "shell.h"
#include "syntax.h"
#include "tree.h"
#include "redirect.h"
#include "execute.h"
#include "signal.h"

#include "../lib/libft.h"

#endif