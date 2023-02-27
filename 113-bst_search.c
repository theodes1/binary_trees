#include "binary_trees.h"
/**
 * bst_search - search in Binary Search Tree
 * @tree: tree root node
 * @value: value n
 * Return: pointer to the node value == node->n
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *aux = (bst_t *)tree;

	while (aux)
	{
		if (aux->n == value)
			return (aux);
		if (aux->n > value)
			aux = aux->left;
		else
			aux = aux->right;
	}
	return (NULL);

}
