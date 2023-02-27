#include "binary_trees.h"
/**
 * array_to_bst -  inserts a values in a Binary Search Tree
 * @array: array
 * @size: size array
 * Return: pointer to the root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i = 0;

	if (size > 0)
	{
		for (; i < size; i++)
			bst_insert(&root, array[i]);
	}
	return (root);
}
