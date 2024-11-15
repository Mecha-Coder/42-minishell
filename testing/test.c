#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define S_QUOTE 1
#define D_QUOTE 2

#define ON 0
#define SQ_OFF 1
#define DQ_OFF 2

int detection(char c, int *state)
{
    if (c == '\"' && *state == ON)     {*state = DQ_OFF; return (1);}
	if (c == '\'' && *state == ON)     {*state = SQ_OFF; return (2);}
	if (c == '\"' && *state == DQ_OFF) {*state = ON; return (3);}
	if (c == '\'' && *state == SQ_OFF) {*state = ON; return (4);}
	return (0);
}

void del_quote(char *s, int type)
{
    int i;
    int j;
    int num;
    int detect;
    char *temp;

    (i = -1, j = 0, detect = ON);
    temp = (char *)malloc(strlen(s) + 1);
    if (!temp)
    {
        perror("Malloc fail");
        exit (EXIT_FAILURE);
    }
    while (s && s[++i])
    {
        num = detection(s[i], &detect);
        if (type == D_QUOTE && num != 1 && num != 3)
            temp[j++] = s[i];
        if (type == S_QUOTE && num != 2 && num != 4)
            temp[j++] = s[i];
    }
    temp[j] = '\0';
    strcpy(s, temp);
    free(temp);
}

void answer(char *s, int type)
{
    printf("Input : %s\n", s);
    del_quote(s, type);
    printf("Output: %s\n"
           "-------------------------\n\n", s);
}

int main()
{
    int type;

    char s1[] = "\"I'm\"";
    char s2[] = "'a's'f'f'g'h";
    char s3[] = "\"a\"s\"f\"g\"h\"";
    char s4[] = "Path \"$SHELL  '  ' && !\"";
    char s5[] = "'A'B'\"C'\"\"";

    char s6[] = "'$username \"USER\"'";
    char s7[] = "'Exit status: $?'";
    char s8[] = "'a's'f'f'g'h";
    char s9[] = "\"a\"s\"f\"g\"h\"";
    char s10[] = "'A'B\"'C'\"";

    printf("Remove double quote"
           "\n====================\n\n");
    type = D_QUOTE;
    answer(s1, type);
    answer(s2, type);
    answer(s3, type);
    answer(s4, type);
    answer(s5, type);

     printf("Remove single quote"
           "\n====================\n\n");
    type = S_QUOTE;
    answer(s6, type);
    answer(s8, type);
    answer(s9, type);
    answer(s7, type);
    answer(s10, type);
}
