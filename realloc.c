#include "main.h"

/**
 **_memset - fills memory with a constant byte
 *@ptr_to_mem: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *ptr_to_mem, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ptr_to_mem[i] = b;
	return (ptr_to_mem);
}

/**
 * ffree - frees a string of strings
 * @str_to_str: string of strings
 */
void ffree(char **str_to_str)
{
	char **a = str_to_str;

	if (!str_to_str)
		return;
	while (*str_to_str)
		free(*str_to_str++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @prev_block: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int prev_block, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == prev_block)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	prev_block = prev_block < new_size ? prev_block : new_size;
	while (prev_block--)
		p[prev_block] = ((char *)ptr)[prev_block];
	free(ptr);
	return (p);
}
