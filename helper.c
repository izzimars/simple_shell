#include "main.h"
/**
 * _strlen - returns the length of a string.
 * Description: 'the program's description'
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
 * buff_print- Entry point
 * Description: 'the program's description'
 * @poutput: Second operand
 *
 * Return: None
 */

void buff_print(char *poutput)
{
	write(STDOUT_FILENO, poutput, _strlen(poutput));
}

/**
 * _strcpy - copies the string pointed to by src,
 * Description: including the terminating null byte, to the
 * @src: source.
 *
 * Return: the pointer to dest.
 */

char *_strcpy(char *src)
{
	int count = 0, i;
	char *dest;

	i = _strlen(src);
	dest = malloc(sizeof(char) * (i + 1));
	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		_memcpy(new_ptr, ptr, old_size);
	else
		_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

/**
 * _execute - returns the length of a string.
 * Description: 'the program's description'
 * @path: input stringeturn.
 * @args: Well spree and great.
 * @envp: well see mmore space.
 *
 * Return: length of a string.
 */
int _execute(char *path, char **args, char **envp)
{
	path = pathchecker(path);
	if (path == NULL)
	{
		return (-1);
	}
	else if (execve(path, args, envp) == -1)
	{
		return (-1);
	}
	return (0);
}
