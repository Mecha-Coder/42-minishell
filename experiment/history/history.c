#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int exit_command(char *input)
{
	int size = 4;

	if (strlen(input) > 4)
		size = strlen(input);

	return !strncmp("exit", input, size);
}

void add_to_history(char *input)
{
	int i = -1;
	HIST_ENTRY **history;

	add_history(input);
	history = history_list();
	printf("\nHistory list\n"
			"*************\n");
	while (history && history[++i])
		printf("%d) %s\n", i + 1, history[i]->line);
	printf("\n");
}

int main()
{   
	char *input;
	
	while (1)
	{
		input = readline("Prompt >> ");
		if (input && input[0]) // Change to !is_empty
		{
			if (exit_command(input))
				break;
			add_to_history(input);
			free(input);
		}
	}
		rl_clear_history(); // Clear history when exit
		printf("History is empty\n");
	return (0);
}