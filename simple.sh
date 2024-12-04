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

    # run_command "< ./file/in"

    # run_command "< nonexit.txt ls | wc -c > ./file/out"
    # run_command "ls -l <./file/in| wc -c > ./file/out"
    # run_command "> ./file/out cat > ./file/out1 < ./file/in"
    # run_command "echo 2 >> ./file/out > ./file/out1"
    # run_command "echo 2 > ./file/out >> ./file/out1"
    # run_command "> ./file/out cat < ./file/in | wc -l"
    # run_command "> ./file/out echo \">>>>> out.txt\" < ./file/in"
    
    # run_command "(echo look) > dsa | tr 'a-z' 'A-Z'"
    # run_command "(echo Hi > dsa && echo Hello) | tr 'a-z' 'A-Z'"
    # run_command "(echo Hi && echo Hello) | tr 'a-z' 'A-Z'"
    # run_command ">> out1.txt cat > && < in.txt"
    # run_command "ls out.txt >"
    # run_command "<<"

    run_command "(echo < sausage) << nonexist.txt"
     run_command "echo Hell && echo Hi && << DONE cat "
    run_command "cat ./dump/fds && echo Hi && << DONE cat"
    run_command ">> ./file/out cat > && < ./file/in"
     run_command "echo Done | cat << EOF"
    run_command "cat > ./file/out | wc -l < ./file/in"
    run_command "< /dev/stdin cat | head -1 > ./file/out"
    run_command "cat << EOF > ./file/out"
    run_command "cat << EOF | wc -l > ./file/out"
    run_command "<< EOF cat | wc -l > ./file/out"
    run_command "cat ./file/in << EOF > ./file/out >> ./file/out2"
    run_command "cat << EOF < ./file/in && echo Hi && << DONE cat"