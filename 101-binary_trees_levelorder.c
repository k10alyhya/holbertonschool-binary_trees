#include "binary_trees.h"

/**
 * tree_levels - Measures the number of levels in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of levels
 */
static size_t tree_levels(const binary_tree_t *tree)
{
	size_t left_levels;
	size_t right_levels;

	if (tree == NULL)
		return (0);

	left_levels = tree_levels(tree->left);
	right_levels = tree_levels(tree->right);

	if (left_levels > right_levels)
		return (left_levels + 1);

	return (right_levels + 1);
}

/**
 * visit_level - Visits all nodes at a specific level
 * @tree: Pointer to the current node
 * @func: Function to call for each node
 * @level: Level to visit
 */
static void visit_level(const binary_tree_t *tree,
	void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
	{
		func(tree->n);
		return;
	}

	visit_level(tree->left, func, level - 1);
	visit_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - Traverses a tree using level-order
 * @tree: Pointer to the root node of the tree
 * @func: Function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t levels;
	size_t level;

	if (tree == NULL || func == NULL)
		return;

	levels = tree_levels(tree);

	for (level = 0; level < levels; level++)
		visit_level(tree, func, level);
}

