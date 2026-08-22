#include "binary_trees.h"

/**
 * avl_check - Checks BST ordering and AVL balance
 * @tree: Pointer to the current node
 * @previous: Pointer to the previously visited node
 * @height: Pointer used to store the subtree height
 *
 * Return: 1 if valid, otherwise 0
 */
static int avl_check(const binary_tree_t *tree,
	const binary_tree_t **previous, size_t *height)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (!avl_check(tree->left, previous, &left_height))
		return (0);

	if (*previous != NULL && tree->n <= (*previous)->n)
		return (0);

	*previous = tree;

	if (!avl_check(tree->right, previous, &right_height))
		return (0);

	if (left_height > right_height + 1 ||
		right_height > left_height + 1)
		return (0);

	if (left_height > right_height)
		*height = left_height + 1;
	else
		*height = right_height + 1;

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL Tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	const binary_tree_t *previous;
	size_t height;

	if (tree == NULL)
		return (0);

	previous = NULL;

	return (avl_check(tree, &previous, &height));
}
