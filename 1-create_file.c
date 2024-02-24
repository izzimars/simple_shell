#include "main.h"
/**
 * _strlen - returns the length of a string.
 * @s: input stringeturn.
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
 * create_file- Entry point
 * Description: 'the program's description'
 * @filename: First operand
 * @text_content: Second operand
 *
 * Return: An int
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t bytes_written;
	int source_fd;
	int i;

	if (!filename)
		return (-1);
	source_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (source_fd == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	i = _strlen(text_content);
	bytes_written = write(source_fd, text_content, i);
	if (bytes_written == -1)
		return (-1);
	close(source_fd);
	return (1);
}
