#include "main.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @ptr_str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *ptr_str, int num)
{
	list_t *nw_head;

	if (!head)
		return (NULL);
	nw_head = malloc(sizeof(list_t));
	if (!nw_head)
		return (NULL);
	_memset((void *)nw_head, 0, sizeof(list_t));
	nw_head->num = num;
	if (ptr_str)
	{
		nw_head->str = _strdup(ptr_str);
		if (!nw_head->str)
		{
			free(nw_head);
			return (NULL);
		}
	}
	nw_head->next = *head;
	*head = nw_head;
	return (nw_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @ptr_str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *ptr_str, int num)
{
	list_t *nw_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	nw_node = malloc(sizeof(list_t));
	if (!nw_node)
		return (NULL);
	_memset((void *)nw_node, 0, sizeof(list_t));
	nw_node->num = num;
	if (ptr_str)
	{
		nw_node->str = _strdup(ptr_str);
		if (!nw_node->str)
		{
			free(nw_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = nw_node;
	}
	else
		*head = nw_node;
	return (nw_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @fir_node: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *fir_node)
{
	size_t i = 0;

	while (fir_node)
	{
		_puts(fir_node->str ? fir_node->str : "(nil)");
		_puts("\n");
		fir_node = fir_node->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @indx: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int indx)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!indx)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == indx)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @hd_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **hd_ptr)
{
	list_t *node, *next_node, *head;

	if (!hd_ptr || !*hd_ptr)
		return;
	head = *hd_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*hd_ptr = NULL;
}
