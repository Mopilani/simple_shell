#include "main.h"

/**
 * _realloc - Reallocate memory for a pointer with new size.
 *
 * @ptr: Pointer to the memory block to reallocate.
 * @new_size: New size (in bytes) for the reallocated memory block.
 * Return: A pointer to the reallocated memory block or NULL on failure.
 */
void *_realloc(void *ptr, size_t new_size)
{
	char *new_mem = NULL;    /* Declare a character pointer variable new_mem. */
	char *temp_ptr = ptr; /* Declare a character pointer variable temp_ptr. */

	if (new_size == 0 && ptr)
	{
		free(ptr); /* If new_size is 0 and ptr is not NULL, free memory. */
		return (NULL);
	}

	if (!ptr && new_size)          /* If ptr is NULL, allocate new memory. */
		return (malloc(new_size));


	new_mem = malloc(new_size); /* Allocate memory for the reallocated block. */
	if (!new_mem)
		return (NULL); /* Return NULL if memory allocation fails. */


	/* if (new_size < old_size)*/
	_strncpy(new_mem, temp_ptr, new_size);    /* Copy data from old to new*/

	/**
	  *if (new_size > old_size)
	  *Copy data from old to new block for sizes larger than the old block.
	  *_strncpy(new_mem, temp_ptr, old_size);
	  */

	free(ptr);      /* Free the old memory block. */
	return (new_mem);   /* Return a pointer to the reallocated memory block. */
}
