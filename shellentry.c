#include "holberton.h"
/**
 * main - function will handle most function calls
 * Return: function will always return 0
 */
int _strcmp(char *s1, char *s2);

int main(void)
{
	char *buff;
	char **commands;
	pid_t pid;
	int status, i, j;
	built in[] = {
		{"exit", exitfxn},
		{NULL, NULL},
	};

	while (1)
	{
		printf("TalkToMe$ ");
		buff = getlinefxn();
		commands = tokenfxn(buff);
		i = 0;
		while (commands != NULL && commands[i] != '\0')
		{
			j = 0;
			while (in[j].command != NULL)
			{
				if (_strcmp(commands[i], (in[i].command)) == 0)
					(in[i].f)(buff, commands);
				j++;
			}
			i++;
		}
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
