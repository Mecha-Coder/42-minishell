#include <stdio.h>
#include <string.h>

#define RESET  "\033[0m"
#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define BLUE   "\033[0;36m"
#define YELLOW "\033[0;33m"


int main()
{
    char s[] = "\033[0;36m\u25A0[999] \033[0;33mMinishell> \033[0m";
    int x = (unsigned char)-1;
    int len = 13;

    if (x)
        s[5] = '1';
    else
        s[5] = '6';
    
    while (len > 10)
    {
        s[len--] = (x % 10) + '0';
        x /= 10;
    }
    printf("%s\n", s);
}
