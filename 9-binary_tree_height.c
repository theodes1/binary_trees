#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftCount = 0, rightCount = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		leftCount = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		rightCount = 1 + binary_tree_height(tree->right);
	if (leftCount > rightCount)
		return (leftCount);
	return (rightCount);
}
