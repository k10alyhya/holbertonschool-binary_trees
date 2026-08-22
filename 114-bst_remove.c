#include <stdlib.h>
#include "binary_trees.h"

/**
 * replace_node - Removes a node with at most one child
 * @root: Pointer to the root node of the BST
 * @node: Pointer to the node to remove
 *
 * Return: Pointer to the new root node
 */
static bst_t *replace_node(bst_t *root, bst_t *node)
{
	bst_t *child;

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	if (child != NULL)
		child->parent = node->parent;

	if (node->parent == NULL)
		root = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;

	free(node);
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;
	bst_t *successor;

	node = root;
	while (node != NULL && node->n != value)
	{
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	if (node == NULL)
		return (root);

	if (node->left != NULL && node->right != NULL)
	{
		successor = node->right;
		while (successor->left != NULL)
			successor = successor->left;

		node->n = successor->n;
		node = successor;
	}

	return (replace_node(root, node));
}
