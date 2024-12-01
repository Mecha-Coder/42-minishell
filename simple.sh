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
    echo -e "${YELLOW}Exit:${NC} $EXIT"

    # Run valgrind and capture its output
    valgrind -q --leak-check=full --error-exitcode=222 ./minishell "$INPUT" &>/dev/null
    if [ $? -eq 222 ]; then
        echo -e "${YELLOW}Valgrind: ${RED}KO${NC}"
    else
        echo -e "${YELLOW}Valgrind: ${GREEN}OK${NC}"
    fi

    if [ $EXIT -eq $EXIT_ACTUAL ]; then
        echo -e "${YELLOW}Compare: ${NC} $EXIT_ACTUAL  ${GREEN}OK${NC}"
    else
        echo -e "${YELLOW}Compare: ${NC} $EXIT_ACTUAL  ${RED}NOT SAME${NC}"
    fi

    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

    run_command "echo"
    run_command "echo -n"
    run_command "echo -n hi"
    run_command "echo -n      \"Hi\""
    run_command "echo   -n   \"Hello \$USER\" ', nice day;)'"
    run_command "echo 'Hi \$\$'"
    run_command "echo '[Hello \"World\"]'"
    run_command "   echo  \"[Hello 'World'']\""
    run_command "echo \"Hello \$USER lol \" -n \"\$SHELL\""
    run_command "echo hello        world ls echo"
    run_command "echo \"Hello               world ls\" go"
    run_command "echo -nnnn Hello World"
    run_command "echo -n -n -nnnn -nnnnm"
    run_command "echo hi\";\" hihi"
    run_command "echo \"Hello\"     \"World\""
    run_command "echo \"Hello\"\"World\""
    run_command "echo \"Hello      World\""
    run_command "echo is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."
    run_command "echo \"EE"
    run_command "export X='i lolo' && ech\$X"
    run_command "export X='i -n lolo' && ech\$X"
    run_command "export X='o -n lolo' && ech\$X"
    run_command "export X='o -n lolo' && ech\"\$X\""
    run_command "echo echo"
    run_command "exit"
    run_command "echo -n hi && exit"
    run_command "rwer || exit"
    run_command "rwer && exit"
