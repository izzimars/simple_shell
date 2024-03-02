#include "main.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL, (*token), (**argv);
	size_t len = 0;
	ssize_t bytes_read;
	int i = 0, j;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			buff_print("#cisfun$ ");
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[bytes_read - 1] == '\n')
			line[bytes_read - 1] = '\0';
		token = strtok(line, " ");
		argv = malloc(sizeof(char *) * 64);
		while (token != NULL)
		{
			argv[i] = _strcpy(token);
			++i;
			if (i == 64)
				argv = _realloc(argv, i, (2 * i));
			token = strtok(NULL, " ");
		}
		if (argv == NULL)
			exit(EXIT_FAILURE);
		argv[i] = NULL;
		if (_strcmp(argv[0], "exit") == 0)
			exit(EXIT_FAILURE);
		else if (_strcmp(argv[0], "env") == 0)
			print_env();
		else if (argv[0] != NULL)
			_execute(argv[0], argv, environ);
		for (j = 0; j < i; j++)
			free(argv[j]);
		free(argv);
		i = 0;
	}
	return (0);
}
