#include "main.h"

/**
 * main - entry point
 * @arg_count: arg count
 * @arg_vec: arg vector
 *
 * Return:if ( success) 0,else  1 on error
 */
int main(int arg_count, char **arg_vec)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (arg_count == 2)
	{
		fd = open(arg_vec[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(arg_vec[0]);
				_puts(": 0: Can't open ");
				_puts(arg_vec[1]);
				_putchar('\n');
				_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_lst(info);
	
	read_history(info);
	
	hsh(info, arg_vec);
	
	return (EXIT_SUCCESS);
}
