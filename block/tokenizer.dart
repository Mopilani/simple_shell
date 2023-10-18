// #include "main.h"

// /**
//  * **strtow - splits a string into words. Repeat delimiters are ignored
//  * @str: the input string
//  * @delim_str:  delimeter string
//  * Return: pointer to an arr of stri, else NULL
//  */

// char **strtow(char *str, char *delim_str)
// {
// 	int i, j, k, m, numwords = 0;
// 	char **s;

// 	if (str == NULL || str[0] == 0)
// 		return (NULL);
// 	if (!delim_str)
// 		delim_str = " ";
// 	for (i = 0; str[i] != '\0'; i++)
// 		if (!is_del(str[i], delim_str) && (is_del(str[i + 1], delim_str)
// 					|| !str[i + 1]))
// 			numwords++;

// 	if (numwords == 0)
// 		return (NULL);
// 	s = malloc((1 + numwords) * sizeof(char *));
// 	if (!s)
// 		return (NULL);
// 	for (i = 0, j = 0; j < numwords; j++)
// 	{
// 		while (is_del(str[i], delim_str))
// 			i++;
// 		k = 0;
// 		while (!is_del(str[i + k], delim_str) && str[i + k])
// 			k++;
// 		s[j] = malloc((k + 1) * sizeof(char));
// 		if (!s[j])
// 		{
// 			for (k = 0; k < j; k++)
// 				free(s[k]);
// 			free(s);
// 			return (NULL);
// 		}
// 		for (m = 0; m < k; m++)
// 			s[j][m] = str[i++];
// 		s[j][m] = 0;
// 	}
// 	s[j] = NULL;
// 	return (s);
// }

// /**
//  * **strtow2 - splits a string into words
//  * @str: the input string
//  * @delim: the delimeter
//  * Return: a pointer to an array of strings, or NULL on failure
//  */
// char **strtow2(char *str, char delim)
// {
// 	int i, j, k, m, numwords = 0;
// 	char **s;

// 	if (str == NULL || str[0] == 0)
// 		return (NULL);
// 	for (i = 0; str[i] != '\0'; i++)
// 		if ((str[i] != delim && str[i + 1] == delim) ||
// 		    (str[i] != delim && !str[i + 1]) || str[i + 1] == delim)
// 			numwords++;
// 	if (numwords == 0)
// 		return (NULL);
// 	s = malloc((1 + numwords) * sizeof(char *));
// 	if (!s)
// 		return (NULL);
// 	for (i = 0, j = 0; j < numwords; j++)
// 	{
// 		while (str[i] == delim && str[i] != delim)
// 			i++;
// 		k = 0;
// 		while (str[i + k] != delim && str[i + k] && str[i + k] != delim)
// 			k++;
// 		s[j] = malloc((k + 1) * sizeof(char));
// 		if (!s[j])
// 		{
// 			for (k = 0; k < j; k++)
// 				free(s[k]);
// 			free(s);
// 			return (NULL);
// 		}
// 		for (m = 0; m < k; m++)
// 			s[j][m] = str[i++];
// 		s[j][m] = 0;
// 	}
// 	s[j] = NULL;
// 	return (s);
// }
