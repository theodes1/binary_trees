#include "binary_trees.h"
/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: value to insert
 * Return: pointer to the uncle node or null
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL, *aux = NULL, *ant = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}
	aux = *tree;
	while (aux)
	{
		ant = aux;
		if (aux->n == value)
			return (NULL);
		if (aux->n > value)
			aux = aux->left;
		else
			aux = aux->right;
	}
	new = binary_tree_node(ant, value);
	if (!ant)
		ant = new;
	if (value > ant->n)
		ant->right = new;
	else
		ant->left = new;
	return (new);
}
