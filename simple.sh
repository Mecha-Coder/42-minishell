#!/bin/bash
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;35m"
NC="\033[0m" # No Color

run_command() {
    INPUT="$1"
    echo -e "${YELLOW}Input: ${NC}"
    echo -e "$INPUT"

    # Capture the command output
    OUTPUT=$(./minishell "$INPUT" 2>&1)
    EXIT=$(echo $? 2>&1)
    ACTUAL=$(bash -c "$INPUT" 2>&1)
    EXIT_ACTUAL=$(echo $? 2>&1)

    echo -e "${YELLOW}Output: ${NC}"
    echo -e "$OUTPUT"
    echo -e "${YELLOW}Actual: ${NC}"
    echo -e "$ACTUAL"

    # Run valgrind and capture its output
    valgrind -q --leak-check=full --error-exitcode=222 ./minishell "$INPUT" &>/dev/null
    if [ $? -eq 222 ]; then
        echo -e "${YELLOW}Valgrind: ${RED}KO${NC}"
    else
        echo -e "${YELLOW}Valgrind: ${GREEN}OK${NC}"
    fi

    echo -e "${YELLOW}Exit:${NC} $EXIT"

    if [ $EXIT -eq $EXIT_ACTUAL ]; then
        echo -e "${YELLOW}Compare: ${NC} $EXIT_ACTUAL  ${GREEN}OK${NC}"
    else
        echo -e "${YELLOW}Compare: ${NC} $EXIT_ACTUAL  ${RED}NOT SAME${NC}"
    fi

    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

    run_command "echo \$USER"
    run_command "echo \$"
    run_command "echo \"\$USER\""
    run_command "echo \$USER"
    run_command "echo \$HOME\$"
    run_command "echo \$PATH"
    run_command "echo \$SHELL"
    run_command "echo \$PWD"
    run_command "echo \$~"
    run_command "echo \"\$\""
    run_command "echo \"\$aa\""
    run_command "echo \$SHELL\$HOME"
    run_command "echo bonjour > \$TEST.txt"
    run_command "echo '\"\$USER\"'  \"'\$USER'\""
    run_command "echo \"[Path \$SHELL  ' \$SHELL ' && XX]\""
    run_command "echo '\$USER'"
    run_command "echo Hi \"there\$USER next\""
    run_command "echo Hi \"there\$USERnext\""
    run_command "echo Hi \"there\$USER\$?next\""
    run_command "echo there\$USER\$!loo"
    run_command "echo there\$USER\$HANTUloo"
    run_command "echo Hi \"there\$USER\$^next\""
    run_command "echo Exit is \$?"
    run_command "echo  User\$USER@42kl"
    run_command "echo \"\$12345\""
    run_command "echo  \$\$!lo\$a:User"
    run_command "echo \"##\$500\""
    run_command "echo \$USER\$!lo\$SWAP_VAR:User\$abc"
    run_command "echo \"\$?Exit is \$?\$?### and \$?'|'\$? \$?\""
    run_command "export a=hi && echo \$a"
    run_command "export a='\"hi             there\"' && echo \$a"
    run_command "export a='hi       there' && echo \$a"
    run_command "export a='hi       there        \$SHELL' && echo \$a"
    run_command "export a='hi       there        \$SHELL      *' && echo \$a"
    run_command "export a=hi  && echo --\$a-Hello"
    run_command "export a='\"hi             there\"' && echo  --\$a-Hello"
    run_command "export a='hi       there' && echo  --\$a-Hello"
    run_command "export a='hi       there        \$SHELL' && echo  --\$a-Hello"
    run_command "export a='hi       there        \$SHELL      *' && echo  --\$a-Hello"
    run_command "export a=hi && echo \"\$a\""
    run_command "export a='\"hi             there\"' && echo \"\$a\""
    run_command "export a='hi       there' && echo \"\$a\""
    run_command "export a='hi       there        \$SHELL' && echo \"\$a\""
    run_command "export a='hi       there        \$SHELL      *' && echo \"\$a\""
    run_command "export a=hi && echo \" --\$a-Hello\""
    run_command "export a='\"hi             there\"' && echo \" --\$a-Hello\""
    run_command "export a='hi       there'  && echo \" --\$a-Hello\""
    run_command "export a='hi       there        \$SHELL' && echo \" --\$a-Hello\""
    run_command "export a='hi       there        \$SHELL      *' && echo \" --\$a-Hello\""
    run_command "export a=' *  \"*\"  *' && echo \$a\"\$a\""
