#include "binary_trees.h"

/**
* bst - binary_tree_is_bst helper
* @tree: pointer to the root node of the tree to check
* @max: min value
* @min: max value
* Return: 1 if tree is a valid BST, and 0 otherwise or if tree NULL
**/
int bst(binary_tree_t *tree, int min, int max)
{
	binary_tree_t *lt, *rt;

	if (tree == NULL)
		return (1);
	lt = (*tree).left;
	rt = (*tree).right;
	if ((*tree).n <= min)
		return (0);
	if ((*tree).n >= max)
		return (0);
	return ((bst(rt, (*tree).n, max)) && (bst(lt, min, (*tree).n)));
}

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid BST, and 0 otherwise or if tree NULL
**/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		return (bst((binary_tree_t *)tree, INT_MIN, INT_MAX));
	}
	return (0);
}
