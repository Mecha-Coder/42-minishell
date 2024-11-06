#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int	is_numeric(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] != '-' && str[i] != '+' && !isdigit(str[i]))
        return(FALSE);

	while (str[++i])
	{
		if (!isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}


int main()
{
    int i = -1;
    char *s[] = {
            "-n",
            "   213421",
            "12321",
            "001",
            "1ewq",
            "ytuvdg2w8",
            "\t\t\n",
            "      ",
            NULL};

    while (s[++i])
    if (is_numeric(s[i]))
        printf("Yes: %s\n", s[i]);
    else
        printf("No: %s\n", s[i]);
}

