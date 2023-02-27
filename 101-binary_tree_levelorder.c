#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through using level-order traversal
 * @tree: root of tree
 * @func: function to print
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func || !tree || (!tree->left && !tree->right && tree->parent))
		return;
	if (!tree->parent)
		(func)(tree->n);
	if (binary_tree_uncle((binary_tree_t *)tree) && tree->parent->left == tree)
		binary_tree_levelorder(binary_tree_uncle((binary_tree_t *)tree), func);

	if (tree->left)
		(func)(tree->left->n);
	if (tree->right)
		(func)(tree->right->n);

	if (binary_tree_uncle((binary_tree_t *)tree) && tree->parent->left == tree)
		binary_tree_levelorder(tree->parent->right, func);
	binary_tree_levelorder(tree->left, func);
	if (!(binary_tree_uncle((binary_tree_t *)tree) && tree->parent->left == tree))
		binary_tree_levelorder(tree->right, func);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node or null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *gf;

	if (!node)
		return (NULL);
	if (!node->parent || !node->parent->parent)
		return (NULL);
	gf = node->parent->parent;
	if (node->parent == gf->left)
		return (gf->right);
	return (gf->left);
}
