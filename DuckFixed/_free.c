#include "main.h"

/**
 * _free - This Function frees any kind of malloc (integer or string).
 * @_mem: The memory location to be freed.
 * @is_dou_p: An indication for whether it is a array of pointers or not.
 * Return: Void.
 */
void _free(void *_mem, int is_dou_p)
{
	int x = 0;
	void **alloc;

	if (is_dou_p)
	{
		alloc = (void **)_mem;

		for (; alloc[x]; x++)
		{
			if (alloc[x])
			{
				free(alloc[x]);
				alloc[x] = NULL;
			}
		}
	}

	if (_mem)
	{
		free(_mem);
		_mem = NULL;
	}

}
