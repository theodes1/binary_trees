#include "binary_trees.h"
int binary_tree_is_bst_(const binary_tree_t *tree, int flag);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree
 * Return: 1 is tree is a valid tree, 0 in other case
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int flag = 0;

	if (!tree)
		return (0);
	return (binary_tree_is_bst_(tree, flag));
}

/**
 * binary_tree_is_bst_ - betty
 * @tree: pointer
 * @flag: flag
 * Return: 1 or 0
 */
int binary_tree_is_bst_(const binary_tree_t *tree, int flag)
{
	binary_tree_t *aux = (binary_tree_t *)tree;

	if (!tree->left && !tree->right)
	{
		aux = aux->parent;
		if (aux)
		{
			aux = aux->parent;
			if (aux && tree->parent->n > aux->n)
				flag = 1;
			if (aux && tree->parent->n < aux->n)
				flag = -1;
			while (aux)
			{
				if (flag == 1)
					if (tree->n <= aux->n)
						return (0);
				if (flag == -1)
					if (tree->n >= aux->n)
						return (0);
				aux = aux->parent;
			}
		}
		return (1);
	}
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			if (tree->n > tree->parent->n)
				return (0);
		if (tree == tree->parent->right)
			if (tree->n < tree->parent->n)
				return (0);
	}
	if (!tree->left)
		return (binary_tree_is_bst(tree->right));
	if (!tree->right)
		return (binary_tree_is_bst(tree->left));
	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}
