#include "shell.h"

/**
 * _memset - fills memory with constant byte
 * @ptr: pointer to memory
 * @b: bytes to fill memory
 * @num: number of bytes to fill
 * Return: ptr
*/
char *_memset(char *ptr, char b, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ptr[i] = b;
	return (ptr);
}

/**
 * ffree - frees a string of strings
 * @ss: string of strings
*/
void ffree(char **ss)
{
	char **p = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(p);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to prev block
 * @prev_sz: byte size of prev block
 * @new_sz: byte size of new block
 * Return: ptr to block
*/

void *_realloc(void *ptr, unsigned int prev_sz, unsigned int new_sz)
{
	char *p;

	if (!ptr)
		return (malloc(new_sz));
	if (!new_sz)
		return (free(ptr), NULL);
	if (new_sz == prev_sz)
		return (ptr);

	p = malloc(new_sz);
	if (!p)
		return (NULL);

	prev_sz = prev_sz < new_sz ? prev_sz : new_sz;
	while (prev_sz--)
		p[prev_sz] = ((char *)ptr)[prev_sz];
	free(ptr);
	return (p);
}
