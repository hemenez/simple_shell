#include "holberton.h"
/**
 * tokenfxn - function will tokenize line
 * @buff: represents pointer to buffer holding line
 * Return: function returns pointer to array
 */

char **tokenfxn(char *buff)
{
	char **commands;
	size_t index;
	char *token;

	commands = malloc(sizeof(char *) * 2);
	if (commands == NULL)
	{
		free(buff);
		return (NULL);
	}
	token = strtok(buff, DELIM);
	commands[0] = token;
	index = 1;
	while (token != NULL)
	{
		commands = realloc(commands, (sizeof(char *) * (index + 1)));
		if (commands == NULL)
		{
			free(buff);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		commands[index] = token;
		index++;
	}
	commands[index] = NULL;
	return (commands);
}
