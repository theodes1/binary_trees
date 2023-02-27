#include "binary_trees.h"
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 is tree is complete, 0 in other case
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *bro;

	if (!tree)
		return (0);

	/* si soy una hoja */
	if (!tree->left && !tree->right)
		return (1);

	/* si tengo solo el hijo right F */
	if (!tree->left && tree->right)
		return (0);

	if (tree->parent)
	{
		if (tree->parent->left != tree)
		{
		/* soy hijo right */
			bro = tree->parent->left;
			if (bro)
			{
				/* si mi bro esta completo (2 hijos) */
				if (bro->left && bro->right)
				{
					if (tree->left &&  !tree->right)
						return (binary_tree_is_complete(tree->left));

				}
				else
					return (0);
				/* si mi bro no esta completo no puedo tener hijos */
			}
		}
	}
	if (tree->left && tree->right)
		return (binary_tree_is_complete(tree->left) &&
				binary_tree_is_complete(tree->right));
	return (binary_tree_is_complete(tree->left));
}
