#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @p: address of pointer to free
 *
 * Return: if free return 1, else 0.
 */
int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
