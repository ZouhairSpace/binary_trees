#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 * @node: A pointer to the root node of the tree to determine the height.
 *
 * Return: 0 if the node is NULL.
 */
size_t binary_tree_height(const binary_tree_t *node)
{
	if (node)
	{
		size_t left_height = 0, right_height = 0;

		left_height = node->left ? 1 + binary_tree_height(node->left) : 0;
		right_height = node->right ? 1 + binary_tree_height(node->right) : 0;

		return ((left_height > right_height) ? left_height : right_height);
	}

	return (0);
}

