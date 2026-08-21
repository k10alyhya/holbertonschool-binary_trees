#include "binary_trees.h"

/**
 * subtree_height - Measures a subtree height in levels
 * @tree: Pointer to the root of the subtree
 *
 * Return: Height in levels
 */
static size_t subtree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);

	return ((int)left_height - (int)right_height);
}
