#include <stdio.h>
#include <string.h>

#define RESET  "\001\e[0m\002"
#define RED    "\001\e[0;31m\002"
#define GREEN  "\001\e[0;32m\002"
#define BLUE   "\\001\e[0;36m\002"
#define YELLOW "\001\e[0;33m\002"

/*
int main()
{
    char s[] = "\001\e[0;31m\002@[999] \001\e[0;33m\002Minishell>\001\e[0m\002 ";
    int x = (unsigned char)-1;
    int len = 13;

    while (len > 10)
    {
        s[len--] = (x % 10) + '0';
        x /= 10;
    }
    printf("%s\n", s);
}*/


// 6 [11-13]
int main()
{
    int i = -1;
    char s[] = "\001\e[0;31m\002@[999] \001\e[0;33m\002Minishell>\001\e[0m\002 ";
    while(s[++i])
        printf("%d : %c\n", i, s[i]);
}




