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
    run_command "cat lol.c | cat > lol.c"
    # run_command "ls | grep \"pattern\" > ./file/result"
    # run_command "cat < ./file/in | wc -l"
    # run_command "echo \"Hello\" > ./file/out && cat nonexist"
    # run_command "echo \"Hello\" && echo \"World\" || echo \"Failed\""
    # run_command "(ls && echo \"Listed\") || echo \"Failed\""
    # run_command "< main.c < a.c cat && cat < main.c"
    # run_command "echo hi || ls && echo world"
    # run_command "echo hi || ls && danjasjdakj || echo world"
    # run_command "echo hi || ls && echo success || echo world"
    # run_command "< ./file/in ls -l | wc -l"
    # run_command "< ./file/in cat | sort | uniq"
    # run_command "< ./file/in ls | cat | cat | cat | cat | cat"
    # run_command "cat ./file/in | cat | cat | cat > ./file/out < in2.txt > ./file/out1"
    # run_command "cat ./file/in | cat | cat > ./file/out | cat >> ./file/out.1 > ./file/err.txt"
    # run_command "export TRY=./file/test && cat ./file/in | cat  > \$TRY"
    # run_command "< ./file/in echo > ./file/out there"
    # run_command "mkdir new_dir && cd 'new_dir'"
    # run_command "echo hi && exit 0"
    # run_command "ls | exit"
    # run_command "exit 0 | exit 1"
    # run_command "exit 0 5 hello \"\$SHELL\""
    # run_command "echo hi && exit 55 70"
    # run_command "> ./file/in && echo done"

