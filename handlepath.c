#include "holberton.h"
/**
 * getpath - function will find the path and append the desired command
 * @commands: represents pointer to first index of command
 * Return: function will return newly concatenated pointer
 */

char *getpath(char *commands)
{
	struct stat st;
	char *stri = "PATH";
	int i, x, k, index;
	char *path = NULL, *finalpath = NULL, *token = NULL, *copy, **tokens = NULL;

	i = 0;
	while (environ[i] != NULL)
	{
		copy = _strdup(environ[i]);
		if (copy == NULL)
		{
			free(copy);
			return (NULL);
		}
		path = strtok(copy, "=");
		if (_strcmp(path, stri) == 0)
		{
			finalpath = environ[i];
		}
		i++;
	}
	token = malloc(sizeof(char) * 1024);
	if (token == NULL)
	{
		free(copy);
		return (NULL);
	}
	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
	{
		free(copy);
		free(token);
		return (NULL);
	}
	token = strtok(finalpath, ":=");
	tokens[0] = token;
	index = 1;
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, ":=");
		index++;
	}
	tokens[index] = NULL;
	k = 0;
	while (tokens != NULL)
	{
		_strcat(tokens[k], "/");
		if (tokens[k] == NULL)
		{
			free(copy);
			free(token);
			free(tokens);
			return (NULL);
		}
		_strcat(tokens[k], commands);
		if (tokens[k] == NULL)
		{
			free(copy);
			free(token);
			free(tokens);
			return (NULL);
		}
		x = stat(tokens[k], &st);
		if (x == 0)
		{
			free(token);
			return (tokens[k]);
		}
		k++;
	}
	free(copy);
	free(token);
	free(tokens);
	return (NULL);
}
