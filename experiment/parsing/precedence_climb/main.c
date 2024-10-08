#include "header.h"

int main() 
{
	int result;

	input = "3 + 5 * (10 - 4)";
	next_token();
	result = parse_expression(0);
	printf("Result: %d\n", result);
	return 0;
}
