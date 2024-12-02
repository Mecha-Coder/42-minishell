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
#include "visual.h" // Remove this

#endif
