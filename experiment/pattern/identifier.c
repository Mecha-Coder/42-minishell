#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_alnum(char c) 
{
    return (is_alphabet(c) || is_digit(c));
}

int is_alphabet(char c) 
{
    return ((c >= 'a' && c <= 'z') 
            || (c >= 'A' && c <= 'Z') 
            || (c == '_'));
}

int is_digit(char c) 
{
    return (c >= '0' && c <= '9');
}

/* Test case
./a.out "hello_world1"
./a.out "42_not_valid"
*/

int is_identifier(char *s)
{
    int i;

    i = 0;
    if (!is_alphabet(s[i]))
        return FALSE;
    while(s[++i])
    {
        if (!is_alnum(s[i]))
            return FALSE;
    }
    return (TRUE);
}

int main(int ac, char **av) 
{    
    if (ac == 2 && av[1][0])
    {
        if (is_identifier(av[1]))
            printf("Valid identifier = \"%s\"\n", av[1]);
        else
            printf("Invalid identifier = \"%s\"\n", av[1]);
    } 
    return 0;
}



