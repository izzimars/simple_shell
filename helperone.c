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
