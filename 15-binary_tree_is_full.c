#include "binary_trees.h"
/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if its full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int leftCount;
	int rightCount;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL)
		leftCount = (binary_tree_is_full(tree->left));
	else
		leftCount = 0;
	if (tree->right != NULL)
		rightCount = (binary_tree_is_full(tree->right));
	else
		rightCount = 0;
	if ((rightCount == 0 && leftCount == 0) || (leftCount != rightCount))
		return (0);
	return (1);
}
