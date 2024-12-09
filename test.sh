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

    run_command "echo \"[Path \$SHELL  '  ' && !]\""
    run_command "echo \"[Path \$SHELL\$]\""
    run_command "echo \"[Test \'still\' valid \$USER]\""
    run_command "echo \"Path: /usr/local/bin\""
    run_command "echo \"It's a beautiful day\""
    run_command "echo \"Exit status: \$?\""
    run_command "echo \"a\"s\"f\"g\"h\""
    run_command "echo \"Double quote: \"\""
    run_command "echo \"Done'\" '"
    run_command "echo \"a\"sf\"g\"h\""
    run_command "echo \"Double' quote: '"
    run_command "echo '[Path \$SHELL \"  \" && !]'"
    run_command "echo '\$USER'"
    run_command "echo 'Hello World'"
    run_command "echo 'Exit status: \$?'"
    run_command "echo 'a's'f'f'g'h"
    run_command "hello"
    run_command "echo 'Done'\" \";"
    run_command "echo 'Single quote: \''"
    run_command "echo 'Done\"' \""
    run_command "echo a's'f'f'g'h"
    run_command "l''s\""
    run_command "try '\"this\""
    run_command "echo 'Single quote: ''"
    run_command "echo \"Done'\" '"