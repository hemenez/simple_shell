#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIM " \t\r\n\a"
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
	return (buff);
}

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
		commands = realloc(commands, (sizeof(char *) * (index + 2)));
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
/**
 * main - function will handle most function calls
 * Return: function will always return 0
 */

int main(void)
{
	char *buff;
	char **commands;
	pid_t pid;
	int status;

	while (1)
	{
		printf("TalkToMe$ ");
		buff = getlinefxn();
		commands = tokenfxn(buff);
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (commands[0] == NULL)
				break;
			execve(commands[0], commands, NULL);
			perror("Error");
		}
		else if (pid > 0)
		{
			pid = wait(&status);
			if (pid < 0)
				perror("wait");
		}
	}
	free(buff);
	free(commands);
	return (0);
}
