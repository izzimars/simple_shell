#ifndef _MAINH_
#define _MAINH_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void buff_print(char *poutput);
int _strlen(char *s);
void _execute(char *path, char **args, char **envp);
char *_strcpy(char *src);
void *_memcpy(void *dest, const void *src, size_t n);

#endif
