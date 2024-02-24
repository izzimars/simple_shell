#include "main.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	char *token;
	int i;
	char **argv;

	while (1)
	{
		buff_print("#cisfun$");
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			perror("Error:");
			exit (-1);
		}
		if (line[bytes_read - 1] == '\n')
			line[bytes_read - 1] = '\0';
		token = strtok(line, " ");
		argv = malloc(sizeof(char *) * 64);
		while (token != NULL)
		{
			argv[i] = _strcopy(token);
			++i;
			if (i == 64)
				argv = _realloc(argv, i, (2 * i));
			token = strtok(NULL, ":");
		}
		argv[i] = NULL;
		if (argv[0] != NULL)
			_execute(argv[0], argv[1], NULL);
	}
}

