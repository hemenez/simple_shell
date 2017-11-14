#include "holberton.h"
/**
 *
 *
 *
 */

void exitfxn(char *buff, char **commands)
{
	free(commands);
	free(buff);
	exit(0);
}
