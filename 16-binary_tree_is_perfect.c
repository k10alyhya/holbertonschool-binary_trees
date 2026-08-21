#include "binary_trees.h"

/**
 * left_depth - Measures the depth of the leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth in levels
 */
static size_t left_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * perfect_check - Checks whether a tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of all leaves
 * @level: Current node level
 *
 * Return: 1 if perfect, otherwise 0
 */
static int perfect_check(const binary_tree_t *tree,
	size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, depth, level + 1) &&
		perfect_check(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = left_depth(tree);

	return (perfect_check(tree, depth, 0));
}
