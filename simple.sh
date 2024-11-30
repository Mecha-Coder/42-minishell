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
    echo -e "${YELLOW}Output: ${NC}"
    echo -e "$OUTPUT"

    # Run valgrind and capture its output
    valgrind -q --leak-check=full --error-exitcode=1 ./minishell "$INPUT" &>/dev/null
    if [ $? -eq 0 ]; then
        echo -e "${YELLOW}Valgrind: ${GREEN}OK${NC}"
    else
        echo -e "${YELLOW}Valgrind: ${RED}KO${NC}"
    fi

    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

run_command "(echo Hi && echo Hello) | tr 'a-z' 'A-Z'"

