#include "binary_trees.h"

/**
* binary_tree_rotate_right - performs a right-rotation on a binary tree
* @tree: pointer to the root node of the tree to rotate
* Return: a pointer to the new root node of the tree once rotated
* NULL if tree is NULL.
**/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *y, *x;

	if (tree != NULL)
	{
		x = tree;
		if ((*x).left != NULL)
		{
			y = (*x).left;
			/*turn y's right subtree into x's left subtree*/
			(*x).left = (*y).right;
			if ((*y).right != NULL)
			{
				(*(*y).right).parent = x;
			}
			/*Link x's parent to y*/
			(*y).parent = (*x).parent;
			if ((*x).parent == NULL)
			{
				tree = y;
			}
			else if (x == (*(*x).parent).right)
			{
				(*(*x).parent).right = y;
			}
			else
			{
				(*(*x).parent).left = y;
			}
			/*put x on y's right*/
			(*y).right = x;
			(*x).parent = y;
			return (tree);
		}
	}
	return (NULL);
}
