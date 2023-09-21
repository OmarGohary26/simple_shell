#include "shell.h"

/**
 * bfree - frees a ptr and makes the address NULL
 * @ptr: address of the ptr
 * Return: 1 when freed, 0 other
*/

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
