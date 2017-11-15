#include "holberton.h"
/**
 *
 *
 */

void envfxn(char *buff, char **commands)
{
	int i;
	(void) buff;
	(void) commands;

	printf("Hi");
	i = 0;
	while(environ[i])
	{
		printf("%s\n", environ[i++]);
	}
	return;
}
