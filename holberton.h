#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/**
 * struct op - represents structure to find builtins
 * @command: represents command to be matched w fxn
 * @f: represents function to be matched according to command
 */

typedef struct op
{
	char *command;
	void (*f)(char *buff, char **commands);
} built;

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIM " \t\r\n\a"

extern char **environ;

char *getlinefxn();
char **tokenfxn(char *buff);
int _strcmp(char *s1, char *s2);
void exitfxn(char *buff, char **commands);
void envfxn(char *buff, char **commands);
int builtinfxn(char *buff, char **commands);


char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *getpath(char *commands);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif
