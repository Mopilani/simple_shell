#include "main.h"

/**
 **_strncpy - string copy
 *@des: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *des, char *src, int n)
{
	int i, x;
	char *s = des;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		des[i] = src[i];
		i++;
	}
	if (i < n)
	{
		x = i;
		while (x < n)
		{
			des[x] = '\0';
			x++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, x;
	char *s = dest;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0' && x < n)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	if (x < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@prs_str:string to be parsed
 *@c: char search
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *prs_str, char c)
{
	do {
		if (*prs_str == c)
			return (prs_str);
	} while (*prs_str++ != '\0');

	return (NULL);
}
