#include "holberton.h"
/**
 * *_strcpy - function will copy a string from one pointer to another
 * Return: function will return string to dest
 * @dest: represents pointer that will receive the copied string
 * @src: represents pointer that holds the string to be copied
 */

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

/**
 * _strdup - function will return pointer to copied string
 * @str: represents string to be copied
 * Return: function will return destination string
 */

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

/**
 * *_strcat - Function will concatenate two strings
 * @src: represents the string that will be added
 * @dest: represents the final appended string
 * Return: the function will return the final appended string
 */

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

/**
 * _strlen - function will return the length of a string
 * Return: function will return zero if compiled correctly
 * @s: represents address given from main function
 */

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
