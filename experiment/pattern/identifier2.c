#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_identifier(char *s);
int is_identifier_tail(char *s);
int is_alnum(char ch);
int is_alphabet(char ch);
int is_digit(char ch);

/* Test case
"hello_world1"
"42_not_valid"
*/

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

int is_identifier(char *s)
{
    if (*s == '\0') 
        return 0;
    if (!is_alphabet(*s))
        return 0;
    return is_identifier_tail(s + 1);
}

int is_identifier_tail(char *s) 
{
    if (*s == '\0') 
        return 1;
    if (is_alnum(*s))
        return is_identifier_tail(s + 1);
    return 0;
}

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
