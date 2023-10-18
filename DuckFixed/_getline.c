#include "main.h"

/**
 *  _getline - Read a line of text from a file descriptor, allocate memory
 * @getlineptr: Pointer to a pointer to the line buffer.
 * @bffsz: Pointer to the buffer size.
 * @f_d: File descriptor to read from.
 * Return: returns the number of characters read
 */
size_t _getline(char **getlineptr, size_t *bffsz, int f_d);
size_t _getline(char **getlineptr, size_t *bffsz, int f_d)
{
	char *buffr = NULL;
	size_t total_rd = 0;
	ssize_t rd;

	if (*bffsz == 0)
		*bffsz = _BFFSZ;

	buffr = (char *)malloc(*bffsz);
	if (buffr == NULL)
	{
		perror("Error: Malloc failed");
		exit(99);
	}
	*getlineptr = buffr;

	do {
		if (total_rd == *bffsz)
		{
			*bffsz *= 2;
			buffr = (char *)_realloc(buffr, *bffsz);
			if (buffr == NULL)
			{
				perror("Error: Realloc failed");
				exit(99);
			}
			*getlineptr = buffr;
		}
		rd = read(f_d, buffr + total_rd, *bffsz - total_rd);
		if (rd < 0)
		{
			perror("Error: Can't read from file");
			free(buffr);
			exit(98);
		}
		else if (rd == 0)
		{
			free(buffr);
			return (-1);
		}
		total_rd += rd;
	} while (rd > 0 && buffr[total_rd - 1] != '\n');

	buffr[total_rd] = '\0';
	return (total_rd);
}
