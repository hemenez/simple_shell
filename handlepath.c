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

char *_strstr(char *haystack, char *needle)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	while (haystack[i] != '\0')
	{
		k = i;
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[k] == needle[j])
				k++;
			else
				break;
		}
		if (needle[j] == '\0')
			return (&haystack[i]);
		i++;
	}
	return (NULL);
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
	char *path;
	char *finalpath;
	char *token = NULL;
	char **tokens = NULL;
	char *copy;

	i = 0;
	while(environ[i] != NULL)
	{
		copy = _strdup(environ[i]);
		path = strtok(copy, "=");
		if (_strcmp(path, stri) == 0)
		{
			finalpath = environ[i];
		}
		i++;
	}
	token = malloc(sizeof(char) * 1024);
	tokens = malloc(sizeof(char) * 1024);
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
		_strcat(tokens[k], commands);
		x = stat(tokens[k], &st);
		if (x == 0)
			return(tokens[k]);
		k++;
	}
	return (NULL);
}
