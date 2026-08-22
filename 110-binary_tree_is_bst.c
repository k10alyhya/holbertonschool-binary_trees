#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_check - Checks BST values using in-order traversal
 * @tree: Pointer to the current node
 * @previous: Pointer to the previously visited node
 *
 * Return: 1 if valid, otherwise 0
 */
static int bst_check(const binary_tree_t *tree,
	const binary_tree_t **previous)
{
	if (tree == NULL)
		return (1);

	if (!bst_check(tree->left, previous))
		return (0);

	if (*previous != NULL && tree->n <= (*previous)->n)
		return (0);

	*previous = tree;

	return (bst_check(tree->right, previous));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *previous;

	if (tree == NULL)
		return (0);

	previous = NULL;

	return (bst_check(tree, &previous));
}
