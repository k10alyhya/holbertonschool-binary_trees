#include "binary_trees.h"

/**
 * insert_node - Inserts a node using BST rules
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the new node, or NULL
 */
static avl_t *insert_node(avl_t **tree, int value)
{
	avl_t *current;
	avl_t *parent;
	avl_t *new_node;

	current = *tree;
	parent = NULL;

	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

/**
 * rebalance_node - Rebalances an AVL subtree
 * @node: Pointer to the subtree root
 * @value: Inserted value
 *
 * Return: Pointer to the new subtree root
 */
static avl_t *rebalance_node(avl_t *node, int value)
{
	int balance;

	balance = binary_tree_balance(node);

	if (balance > 1)
	{
		if (value > node->left->n)
			binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance < -1)
	{
		if (value < node->right->n)
			binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * avl_insert - Inserts a value into an AVL Tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;
	avl_t *ancestor;
	avl_t *subtree_root;

	if (tree == NULL)
		return (NULL);

	new_node = insert_node(tree, value);
	if (new_node == NULL)
		return (NULL);

	ancestor = new_node->parent;
	while (ancestor != NULL)
	{
		subtree_root = rebalance_node(ancestor, value);
		if (subtree_root->parent == NULL)
			*tree = subtree_root;
		ancestor = subtree_root->parent;
	}

	return (new_node);
}
