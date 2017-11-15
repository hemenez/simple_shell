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
	char *buff;
	char **commands;
	pid_t pid;
	int status, x;

	while (1)
	{
		write(STDOUT_FILENO, "TalkToMe$ ", 11);
		buff = getlinefxn();
		commands = tokenfxn(buff);
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
				execve(commands[0], commands, NULL);
				perror("Error");
			}
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
