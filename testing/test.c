#include <stdio.h>
#include <ctype.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s && *s)
	{
		counter++;
		s++;
	}
	return (counter);
}

int main()
{
    printf("%ld", ft_strlen(NULL));
}