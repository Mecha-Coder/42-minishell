#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#include "struct.h"
#include "constant.h"
#include "utils.h"
#include "expand.h"
#include "built_in.h"
#include "env.h"
#include "token.h"
#include "shell.h"

#include "../lib/libft.h"

#include "visual.h" // Remove this

#endif