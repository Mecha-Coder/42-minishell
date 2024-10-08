#include <stdio.h>

/* Test case
./a.out '			'
./a.out  '	'
./a.out  ''
./a.out  '    '
./a.out  '   hello'
*/

int is_blank(char *s)
{
	int i = -1;

	while(s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
	}
	return 1;
}

int main(int ac, char **av) 
{    
	if (ac == 2 && av[1][0])
	{
		if (is_blank(av[1]))
			printf("Is blank = \"%s\"\n", av[1]);
		else
			printf("Not blank = \"%s\"\n", av[1]);
	} 
	return 0;
}




