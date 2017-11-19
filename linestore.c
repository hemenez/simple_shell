#include "holberton.h"
/**
 * getlinefxn - function will get line and store in a buffer
 * Return: returns pointer to buffer
 */

char *getlinefxn()
{
	char *buff = NULL;
	size_t buffsize = 0;
	ssize_t x;

	x = getline(&buff, &buffsize, stdin);
	if (buff == NULL)
	{
		perror("Error");
		return (NULL);
	}
	if (x == -1)
	{
		free(buff);
		return (NULL);
	}
	if (x == 1)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
