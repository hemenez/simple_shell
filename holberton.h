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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define DELIM " \t\r\n\a"
#define BUFFERSIZE 1024

extern char **environ;

char *getlinefxn();
char **tokenfxn(char *buff);
int _strcmp(char *s1, char *s2);
void exitfxn(char *buff, char **commands);
void envfxn(char *buff, char **commands);
int builtinfxn(char *buff, char **commands);
char *find_path(char *command);
char **tokenize_path(unsigned int index, char *s);
int path_strcmp(char *s);
unsigned int path_counter(char *s, const char *delimiter);
char **token_help(char *path, const char *delimiter, int path_count);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void path_token_free(char **path_token);

#endif
