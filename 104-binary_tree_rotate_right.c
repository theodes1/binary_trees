#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux = NULL;

	if (tree == NULL)
		return (tree);
	aux = tree->left;
	aux->parent = tree->parent;
	if (aux->right != NULL)
	{
		tree->left = aux->right;
		aux->right->parent = tree;
	}
	else
		tree->left = NULL;
	aux->right = tree;
	tree->parent = aux;
	return (aux);
}
