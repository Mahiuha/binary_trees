#include "binary_trees.h"

/**
* tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree to measure the size
* Return: size of a binary tree
* If tree is NULL, the function must return 0
**/
size_t tree_size(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	count = 1 + tree_size((*tree).left) + tree_size((*tree).right);
	return (count);
}

/**
* is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* @pos: position of node
* @nodes: size of the tree
* Return: 1 is tree is perfect, 0 if not or tree is NULL
**/
int is_complete(binary_tree_t *tree, int pos, int nodes)
{
	int left, right;

	if (tree == NULL)
	{
		return (1);
	}
	if (pos >= nodes)
	{
		return (0);
	}
	left = is_complete((*tree).left, 2 * pos + 1, nodes);
	right = is_complete((*tree).right, 2 * pos + 2, nodes);
	return (left * right);
}

/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* Return: 1 is tree is perfect, 0 if not or tree is NULL
**/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes, pos = 0;

	if (tree != NULL)
	{
		nodes = tree_size(tree);
		return (is_complete((binary_tree_t *)tree, pos, nodes));
	}
	return (0);
}
