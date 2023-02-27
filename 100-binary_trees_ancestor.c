#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest ancestor of two nodes
 * @first: 1st node
 * @second: 2d node
 * Return: pointer to the ancestor or null
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *aux1 = (binary_tree_t *)first, *aux2;

	if (!first || !second)
		return (NULL);

	while (aux1)
	{
		aux2 = (binary_tree_t *)second;
		while (aux2)
		{
			if (aux1 == aux2)
				return (aux1);
			aux2 = aux2->parent;
		}
		aux1 = aux1->parent;
	}
	return (NULL);
}
