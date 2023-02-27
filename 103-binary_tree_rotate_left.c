#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux = NULL;

	if (tree == NULL)
		return (tree);
	aux = tree->right;
	aux->parent = tree->parent;
	if (aux->left != NULL)
	{
		tree->right = aux->left;
		aux->left->parent = tree;
	}
	else
		tree->right = NULL;
	aux->left = tree;
	tree->parent = aux;
	return (aux);
}
