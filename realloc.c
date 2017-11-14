#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size of the allocated space for ptr
 * @new_size: the new size to be allocated
 * Return: pointer to reallocated array or NULL if new_size = 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *holder_array;
	char *p;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	p = (char *)ptr;
	holder_array = malloc(sizeof(char) * new_size);
	if (holder_array == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		for (i = 0; i < old_size; i++)
			holder_array[i] = p[i];
	}
	free(ptr);
	return (holder_array);
}
