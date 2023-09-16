#include "shell.h"

/**
 * _strlen - returns length of string
 * @s: string
 * Return: int length of string
*/

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - does lexicographic comparison of 2 strings
 * @s1: first string
 * @s2: second string
 * Return: -1 if s1 < s2, 1 if s1 > s2, 0 if equal
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * strt_w - checks if needle starts with haystack
 * @haystack: string
 * @needle: substring to find
 * Return: address of next char of haystack or NULL
*/

char *strt_w(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concats 2 strings
 * @dest: destination buf
 * @src: source buf
 * Return: ptr to dest buf
*/

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ptr);
}
