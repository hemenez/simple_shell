#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIM " \t\r\n\a"
/**
 * main - function will replicate shell system
 * Return: function returns zero upon success, one on error
 */

int main(void)
{
	char *commands[7];
	pid_t pid;
	int status;
	ssize_t x;
	int index;
	char *token;
	size_t buffsize = 0;
	char *buff = NULL;

	while (1)
	{
		printf("TalkToMe$ ");
		x = getline(&buff, &buffsize, stdin);
		if (buff == NULL)
		{
			perror("Error");
			return (1);
		}
		if (x == -1)
		{
			free(buff);
			return (1);
		}
		token = strtok(buff, DELIM);
		index = 0;
		while (token != NULL)
		{
			commands[index] = token;
			token = strtok(NULL, DELIM);
			index++;
		}
		commands[index] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");

			return (1);
		}
		if (pid == 0)
		{
			if (commands[0] == NULL)
			{
				break;
			}
			/* Child process */
			execve(commands[0], commands, NULL);
			/* Only reaches if error executing */
			perror("Error");
		}
		else if (pid > 0)
		{
			/* Parent process */
			pid = wait(&status);
			if (pid < 0)
			{
				perror("wait");
				free(buff);
				exit(1);
			}
		}
	}
	free(token);
	free(buff);
	return (0);
}
