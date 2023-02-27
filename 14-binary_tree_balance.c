#include "binary_trees.h"
/**
 * binary_tree_balance_h - height
 * @tree: pointerto the root node of the tree
 * Return: height or if tree is NULL return 0
 */
int binary_tree_balance_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_balance_h(tree->left) > binary_tree_balance_h(tree->right))
		return (1 + binary_tree_balance_h(tree->left));
	else
		return (1 + binary_tree_balance_h(tree->right));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: balance factor or if tree is NULL return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_balance_h(tree->left) -
			binary_tree_balance_h(tree->right));
}
