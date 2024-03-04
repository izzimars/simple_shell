#include "main.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL, (**argv);
	size_t len = 0;
	int j, status;
	pid_t child_pid;

	while (1)
	{
		display_line(&line, &len);
		argv = malloc(sizeof(char *) * 64);
		argv = space_allocation(argv, line);
		if (argv == NULL)
			exit(EXIT_FAILURE);
		if (_strcmp(argv[0], "exit") == 0)
			exit(0);
		else if (_strcmp(argv[0], "env") == 0)
			print_env();
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(1);
			}
			if ((child_pid == 0) && (_execute(argv[0], argv, environ) == -1))
				perror("Error:");
			else
			{
				wait(&status);
				sleep(1);
			}
		}
		for (j = 0; argv[j] != NULL; j++)
			free(argv[j]);
		free(argv);
	}
	return (0);
}
