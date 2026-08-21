#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ?
		1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ?
		1 + binary_tree_height(tree->right) : 0;

	if (left_height > right_height)
		return (left_height);

	return (right_height);
}
