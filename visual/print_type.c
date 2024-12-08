/* 
- This is for visual only
- remove after done with project 
*/

#include "../include/minishell.h"

void print_type_1(int i)
{
    if (i == 1)      printf("%-7s", "<AND>");
    else if (i == 2) printf("%-7s","<OR>");
    else if (i == 3) printf("%-7s","<PIPE>");
    else if (i == 4) printf("%-7s","<HERE>");
    else if (i == 5) printf("%-7s","<RD>");
    else if (i == 6) printf("%-7s","<APPD>");
    else if (i == 7) printf("%-7s","<WR>");
    else if (i == 8) printf("%-7s","<OB>");
    else if (i == 9) printf("%-7s","<CB>");
    else if (i == 10) printf("%-7s","<STR>");
    else if (i == 11) printf("%-7s","EXE");
    else if (i == 12) printf("%-7s","SUB");
}


void print_type_2(int i)
{
    if (i == 1)      printf("<AND>");
    else if (i == 2) printf("<OR>");
    else if (i == 3) printf("<PIPE>");
    else if (i == 4) printf("<HERE>");
    else if (i == 5) printf("<RD>");
    else if (i == 6) printf("<APPD>");
    else if (i == 7) printf("<WR>");
    else if (i == 8) printf("<OB>");
    else if (i == 9) printf("<CB>");
    else if (i == 10) printf("<STR>");
    else if (i == 11) printf("<EXE>");
    else if (i == 12) printf("<SUB>");
}