#include "holberton.h"

/**
 * find_path - finds the path of the given command
 * @command: the command to be found
 * Return: the full path of the command or NULL if fails
 */
char *find_path(char *command)
{
	char *str = "PATH", *path;
	char **path_token;
	unsigned int i;
	int s, len;
	struct stat buf;

	i = path_strcmp(str);
	path_token = tokenize_path(i, str);
	if (path_token == NULL)
		return (NULL);
	for (i = 0; path_token[i] != NULL; i++)
	{
		path = path_token[i];
		len = _strlen(path);
		path[len] = '/';
		path[len + 1] = '\0';
		path = _strcat(path, command);
		s = stat(path, &buf);
		if (s == 0)
		{
			path_token_free(path_token);
			return (path);
		}
	}
	path_token_free(path_token);
	return (NULL);
}

/**
 * tokenize_path - tokenizes the PATH
 * @s: string to be tokenized
 * @index: the index to begin at
 * Return: Tokenized string or NULL on fail
 */
char **tokenize_path(unsigned int index, char *s)
{
	char *env_path, **path_token;
	const char *delimiter = ":";
	int path_count = 0, len = _strlen(s);

	env_path = environ[index] + (len + 1);
	path_token = token_help(env_path, delimiter, path_count);
	if (path_token == NULL)
		return (NULL);
	return (path_token);
}

/**
 * path_strcmp - finds PATH in the environ variable
 * @s: the string to compare against
 * Return: index of PATH or -1 if fails
 */
int path_strcmp(char *s)
{
	unsigned int i, index, len;

	len = _strlen(s);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (index = 0; index < len; index++)
		{
			if (environ[i][index] != s[index])
				break;
		}
		if (index == len && environ[i][index] == '=')
			return (i);
	}
	return (-1);
}

/**
 * path_counter - counts the tokens to be made for path
 * @s: string to be tokenized
 * @delimiter: the delimiter to be used to tokenize
 * Return: the amount of tokens to be created
 */
unsigned int path_counter(char *s, const char *delimiter)
{
	unsigned int i;
	char *copy, *token;

	copy = _strdup(s);
	if (copy == NULL)
		return (-1);
	token = strtok(copy, delimiter);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delimiter);
	free(copy);
	return (i);
}


/**
 * token_help - helper function to tokenize PATH
 * @path: the string containing path to be tokenized
 * @delimiter: the delimiter to use to tokenize
 * @path_count: holder for the amount of tokens in the string
 * Return: an array of the tokenized path
 */
char **token_help(char *path, const char *delimiter, int path_count)
{
	char **path_token, *token, *path_cp;
	int i;

	path_count = path_counter(path, delimiter);
	if (path_count == -1)
	{
		free(path);
		return (NULL);
	}
	path_cp = _strdup(path);
	path_token = malloc(sizeof(char *) * (path_count + 2));
	if (path_token == NULL)
		return (NULL);
	token = strtok(path_cp, delimiter);
	for (i = 0; token != NULL; i++)
	{
		path_token[i] = _strdup(token);
		token = strtok(NULL, delimiter);
	}
	path_token[i] = NULL;
	free(path_cp);
	return (path_token);
}
