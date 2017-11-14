#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/**
 *
 */

typedef struct op
{
	char *command;
	void(*f)(char *buff, char **commands);
} built;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIM " \t\r\n\a"

char *getlinefxn();
char **tokenfxn(char *buff);
int _strcmp(char *s1, char *s2);
void exitfxn(char *buff, char **commands);

#endif
