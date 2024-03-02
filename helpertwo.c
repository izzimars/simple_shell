#include "main.h"
/**
 * space_allocation - returns the length of a string.
 * Description: 'the program's description'
 * @args: Well spree and great.
 * @token: well see mmore space.
 *
 * Return: length of a string.
 */
char **space_allocation(char **argv, char *token)
{
	int i = 0;

	if (argv == NULL)
		return (argv);
	token = strtok(token, "  \t\n");
	while (token != NULL)
	{
		argv[i] = _strcpy(token);
		++i;
		if (i == 64)
		{
			argv = _realloc(argv, i, (2 * i));
			if (argv == NULL)
				return (argv);
		}
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * display_line - returns the length of a string.
 * Description: 'the program's description'
 * @line: Well spree and great.
 * @len: well see mmore space.
 *
 * Return: length of a string.
 */
void display_line(char **line, size_t *len)
{
	ssize_t bytes_read;
	
	if (isatty(STDIN_FILENO) == 1)
		buff_print("#cisfun$ ");
	bytes_read = getline(line, len, stdin);
	if (bytes_read == -1)
	{
		free(*line);
		exit(EXIT_FAILURE);
        }
}
