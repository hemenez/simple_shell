#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIM " \t\r\n\a"

char *getlinefxn();
char **tokenfxn(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
