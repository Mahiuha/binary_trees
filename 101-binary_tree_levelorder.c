#include "binary_trees.h"

/**
* scale - aux function that measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
* Return: height of a binary tree, 0 is tree is NULL
**/
int scale(const binary_tree_t *tree)
{
	int ll = 1;
	int lr = 1;

	if (tree == NULL)
	{
		return (-1);
	}
	ll += scale((*tree).left);
	lr += scale((*tree).right);
	if (lr > ll)
	{
		return (lr);
	}
	return (ll);
}

/**
* print_level - aux function to level travel
* using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
* @level: actual level
**/
void print_level(binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree != NULL)
	{
		if (level == 0)
		{
			func((*tree).n);
		}
		else
		{
			print_level((*tree).left, level - 1, func);
			print_level((*tree).right, level - 1, func);
		}
	}
}

/**
* binary_tree_levelorder - goes through a binary tree
* using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
**/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level, height;

	if (tree != NULL && func != NULL)
	{
		height = scale(tree) + 1;
/*		printf("Level: %i\n", height);*/
		for (level = 0; level < height; level++)
		{
			print_level((binary_tree_t *)tree, level, func);
		}
	}
}
