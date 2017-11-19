#include "holberton.h"
/**
 * _strcmp - function will compare two strings
 * @s1: represents pointer to first string
 * @s2: represents pointer to second string
 * Return: function will return a number based off comparison of strings
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] < s2[a] || s1[a] > s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

#include "holberton.h"

/**
 * _strlen - takes input from main
 * @s: pointer to input from main
 * Description: returns the length of a string
 * Return: nothing
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

#include "holberton.h"

/**
 * _strcat - Takes input from main function.
 * @dest: Return value to be returned to main function.
 * @src: String given from main function.
 * Description: Takes two strings and concatenates them.
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int length;
	int counter;

	length = 0;
	counter = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	while (src[counter] != '\0')
	{
		dest[length + counter] = src[counter];
		counter++;
	}
	dest[length + counter] = '\0';
	return (dest);
}

#include "holberton.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to be duplicated
 * Return: NULL if insufficent space else a pointer to beginning of array
 */
char *_strdup(char *str)
{
	int index;
	char *holder_array;

	holder_array = malloc(BUFFERSIZE);
	if (holder_array == NULL)
		return (NULL);
	for (index = 0; str[index] != '\0'; index++)
		holder_array[index] = str[index];
	holder_array[index] = '\0';
	return (holder_array);
}
