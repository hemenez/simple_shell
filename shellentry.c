#include "holberton.h"
/**
 * builtinfxn - function will see if input is a shell builtin
 * @buff: represents buffer to be read
 * @commands: represents commands to be analyzed
 * Return: returns zero if builtin, one if not
 */

int builtinfxn(char *buff, char **commands)
{
	int i, j;
	built in[] = {
		{"exit", exitfxn},
		{"env", envfxn},
		{NULL, NULL},
	};

	i = 0;
	while (commands != NULL && commands[i] != '\0')
	{
		j = 0;
		while (in[j].command != NULL)
		{
			if (_strcmp(commands[i], (in[j].command)) == 0)
			{
				(in[j].f)(buff, commands);
				free(buff);
				free(commands);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * main - function will handle most function calls
 * Return: function will always return 0
 */

int main(void)
{
	char *buff, **commands;	pid_t pid; int status, x, y; struct stat st;

	while (1)
	{
		write(STDOUT_FILENO, "TalkToMe$ ", 11);
		buff = getlinefxn();
		if (buff == NULL)
			break;
		commands = tokenfxn(buff);
		if (commands == NULL)
		{
			free(buff);
			free(commands);
			break;
		}
		x = builtinfxn(buff, commands);
		if (x == 0)
			continue;
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			if (commands[0] != NULL)
			{
				y = stat(commands[0], &st);
				if (y != 0)
					commands[0] = getpath(commands[0]);
				execve(commands[0], commands, NULL);
				perror("Error");
			}
			else
				free(buff); free(commands);
		}
		else if (pid > 0)
		{
			pid = wait(&status);
			if (pid < 0)
				perror("wait");
			free(buff);
			free(commands);
		}
	}
	return (0);
}
