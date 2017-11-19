#include "holberton.h"
char *_strcpy(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	return (dest);
}

char *_strdup(char *str)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	ptr = malloc(_strlen(str) + 1);
	if (ptr != NULL)
		_strcpy(ptr, str);
	return (ptr);
}

char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;

	while (dest[b] != '\0')
	{
		b++;
	}
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}
int _strlen(char *s)
{
	int length;

	length = 0;
	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}
extern char **environ;
char *getpath(char *commands)
{
	struct stat st;
	char *stri = "PATH";
	int i, x, k;
	int index;
	char *path = NULL;
	char *finalpath = NULL;
	char *token = NULL;
	char **tokens = NULL;
	char *copy;

	i = 0;
	while(environ[i] != NULL)
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
	while(token != NULL)
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
			return(tokens[k]);
		}
		k++;
	}
	free(copy);
	free(token);
	free(tokens);
	return (NULL);
}
