#include "binary_trees.h"

/**
 * binary_tree_leaves - Calculates the number of leaves in a binary tree.
 *
 * @node: A pointer to the root node of the tree to count the leaves.
 *
 * Return: 0 if the node is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *node)
{
	size_t leaves = 0;

	if (node)
	{
		leaves += (!node->left && !node->right) ? 1 : 0;
		leaves += binary_tree_leaves(node->left);
		leaves += binary_tree_leaves(node->right);
	}

	return (leaves);
}

