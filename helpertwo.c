#include "main.h"

ssize_t custom_getline(char **lineptr, size_t *n, int stream) {
	size_t bufsize = *n, pos = 0;
	int c;
	ssize_t bytes_read;

	if (lineptr == NULL || n == NULL)
		return -1;
	if (*lineptr == NULL)
	{
		bufsize = 128;
		*lineptr = malloc(bufsize);
		if (*lineptr == NULL)
			return -1;
	}
	while (1)
	{
		bytes_read = read(stream, &c, 1);
		if (bytes_read == -1)
			return -1;
		if (c == EOF)
			break;
		else if (bytes_read == 0 && pos == 0)
				return 0;
		else if (bytes_read == 0)
				break;
		else if (c == '\n' || c == '\r')
		{
			(*lineptr)[pos] = '\0';
			return pos;
		}
		(*lineptr)[pos++] = c;
		if (pos >= bufsize - 1)
		{
			lineptr = _realloc(lineptr, bufsize, (2 * bufsize));
			if (lineptr == NULL)
				return -1;
		}
	}
	(*lineptr)[pos] = '\0';
	*n = bufsize;
	return pos;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;

    while (1)
    {
        printf("$ ");
        bytes_read = custom_getline(&line, &len, STDIN_FILENO);
        if (bytes_read == -1)
            break;
        printf("%s", line);
    }
    if (line != NULL)
    {
        free(line);
    }
    return 0;
}
