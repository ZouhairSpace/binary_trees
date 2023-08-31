#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a left child to a binary tree.
 *
 * @node: A pointer to the node to which the left child is added.
 * @val: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *node, int val)
{
	binary_tree_t *new_child;

	if (node == NULL)
		return (NULL);

	new_child = binary_tree_node(node, val);
	if (new_child == NULL)
		return (NULL);

	if (node->left != NULL)
	{
		new_child->left = node->left;
		node->left->parent = new_child;
	}
	node->left = new_child;

	return (new_child);
}

