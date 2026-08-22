#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;
	binary_tree_t *middle;
	binary_tree_t *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	parent = tree->parent;
	new_root = tree->left;
	middle = new_root->right;

	new_root->parent = parent;
	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = new_root;
		else if (parent->right == tree)
			parent->right = new_root;
	}

	new_root->right = tree;
	tree->parent = new_root;
	tree->left = middle;

	if (middle != NULL)
		middle->parent = tree;

	return (new_root);
}
