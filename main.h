#ifndef _MAINH_
#define _MAINH_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

void display_line(char **line, size_t *len);
char **space_allocation(char **argv, char *token);
void buff_print(char *poutput);
int _strlen(char *s);
int _execute(char *path, char **args, char **envp);
char *_strcpy(char *src);
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *pathchecker(char *av);
int _strcmp(char *s1, char *s2);
void print_env(void);
ssize_t custom_getline(char **lineptr, size_t *n, int stream);

#endif
