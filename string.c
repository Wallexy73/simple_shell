#include "shell.h"

/**
 *  _strcmp - compares two strings
 *  @s1: char pointer
 *  @s2: char pointer
 *  _strlen - returns the length of a string
 *  @s: the string whose length to check
 *
 *  _strcmp: compares two strings at the same spot on each string
 *  Return: positive, negative, or 0 if theyre the same
 *  Return: integer length of string
 */
int _strcmp(char *s1, char *s2)
int _strlen(char *s)
{
	int i;
	int i = 0;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	if (!s)
		return (0);

	while (*s++)
		i++;
	}
	return (s1[i] - s2[i]);
	return (i);
}
/**
 *  _strlen - counts the length of the string
 *  @str: string
 *  Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t length = 0;

	while (*str++)
		length++;

	return (length);
}
/**
 *  _strcpy - string copy
 *  @dest: dest string
 *  @src: source string
 *  Return: string
 *  _strcmp - performs lexicogarphic comparison of two strangs.
 *  @s1: the first strang
 *  @s2: the second strang
 *
 *  Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
char *_strcpy(char *dest, char *src)
int _strcmp(char *s1, char *s2)
{
	char *ptr = dest;

	while (*src)
		*ptr++ = *src++;
	*ptr = *src;

	return (dest);
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
 * _strdup - string duplication
 * @str: string
 * Return: string
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_strdup(char *str)
char *starts_with(const char *haystack, const char *needle)
{
	char *new;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (_strlen(str) + 1));
	if (new == NULL)
		return (NULL);
	_strcpy(new, str);
	return (new);
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 *  _strcat - string concnat
 *  @dest: destination
 * @src: source
 * Return: concated string
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ptrs = dest;
	char *ret = dest;

	while (*ptrs)
		ptrs++;
	while (*dest)
		dest++;
	while (*src)
		*ptrs++ = *src++;
	*ptrs = 0;
	return (dest);
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
