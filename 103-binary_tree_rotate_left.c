#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
* Return: a pointer to the new root node of the tree once rotated
* NULL if tree is NULL.
**/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *y, *x;

	if (tree != NULL)
	{
		x = tree;
		if ((*x).right != NULL)
		{
			y = (*x).right;
			/*turn y's left subtree into x's right subtree*/
			(*x).right = (*y).left;
			if ((*y).left != NULL)
			{
				(*(*y).left).parent = x;
			}
			/*Link x's parent to y*/
			(*y).parent = (*x).parent;
			if ((*x).parent == NULL)
			{
				tree = y;
			}
			else if (x == (*(*x).parent).left)
			{
				(*(*x).parent).left = y;
			}
			else
			{
				(*(*x).parent).right = y;
			}
			/*put x on y's left*/
			(*y).left = x;
			(*x).parent = y;
			return (tree);
		}
	}
	return (NULL);
}
