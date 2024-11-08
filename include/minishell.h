#ifndef MINISHELL_H
#define MINISHELL_H

// Mute this headers after finalize
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <sys/ioctl.h>

#include "constant.h"
#include "struct.h"
#include "built_in.h"
#include "env.h"
#include "execute.h"
#include "parse.h"
#include "utils.h"
#include "signal.h"

#include "../lib/libft.h"

#endif
