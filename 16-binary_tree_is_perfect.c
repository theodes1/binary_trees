#include "binary_trees.h"
int binary_tree_h(const binary_tree_t *tree);
int binary_tree_s(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is perfect, 0 in other case
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree &&
	(binary_tree_s(tree->left) == binary_tree_s(tree->right) &&
	binary_tree_h(tree->left) == binary_tree_h(tree->right)))
		return (1);
	return (0);
}


/**
 * binary_tree_s - size
 * @tree: pointer to the root node of the tree
 * Return: size of a tree
 */
int binary_tree_s(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_s(tree->left) +
			binary_tree_s(tree->right));
}

/**
 * binary_tree_h - height
 * @tree: pointer to the root node of the tree
 * Return: height or if tree is NULL return 0
 */
int binary_tree_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_h(tree->left) > binary_tree_h(tree->right))
		return (1 + binary_tree_h(tree->left));
	else
		return (1 + binary_tree_h(tree->right));
}
