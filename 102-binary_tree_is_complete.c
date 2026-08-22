#include "binary_trees.h"

/**
 * tree_size - Counts the nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * complete_check - Checks node positions in a complete binary tree
 * @tree: Pointer to the current node
 * @index: Expected array index of the node
 * @size: Total number of nodes
 *
 * Return: 1 if complete, otherwise 0
 */
static int complete_check(const binary_tree_t *tree,
	size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (complete_check(tree->left, 2 * index + 1, size) &&
		complete_check(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);

	return (complete_check(tree, 0, size));
}
