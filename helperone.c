#include "main.h"
/**
 * _memcpy - returns a pointer to a newly allocated space in memory.
 * @dest: string.
 * @src: string
 * @n: int
 *
 * Return: pointer of an array of chars
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;
	size_t i;

	if (dest == NULL || src == NULL)
		return NULL;
	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];
	return dest;
}

/**
 * *_strcat - function commute srtings
 * @dest: param pointer to a char
 * @src: param pointer to a char
 * Return: return value of dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if (i > 3)
			break;
		op = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (op);
}

/**
 * pathchecker - returns a pointer to a newly allocated space in memory.
 * @av: string.
 *
 * Return: pointer of an array of chars
 */
char *pathchecker(char *av)
{
	struct stat st;
	char **env;
	char *p;
	char *token;
	char path[1024] = "";

	if (stat(av, &st) == 0)
		return (av);
	for (env = environ; *env != NULL; env++)
	{
		if(_strcmp(*env, "PATH") == 0)
			break;
	}
	p = *env;
	p = p + 5;
	token = strtok(p, ":");
	while (token != NULL)
	{
                _strcat(path, token);
                _strcat(path, "/");
                _strcat(path, av);
		if (stat(path, &st) == 0)
		{
			av = path;
			return (av);
		}
		else
			path[0] = '\0';
		token = strtok(NULL, ":");
	}
	return (0);
}

/**
 * print_env - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */
void print_env()
{
	char **env;
	unsigned int i;

	i = 0;
	env = environ;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
