#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common
* ancestor of two nodes
* @first: pointer to the first node
* @second: pointer to the second node
* Return: a pointer to the lowest common ancestor node of the two
* given nodes. If no common ancestor was found returns NULL
**/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *tur = NULL, *rab = NULL;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	rab = (binary_tree_t *)second;
	while (rab != NULL)
	{
		tur = (binary_tree_t *)first;
		while (tur != NULL)
		{
			if (tur != rab)
				tur = (*tur).parent;
			else
			{
				return (tur);
			}
		}
		rab = (*rab).parent;
	}
	return (NULL);
}
