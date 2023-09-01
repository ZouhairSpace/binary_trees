#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 *
 * @node: A pointer to the node to determine the depth.
 *
 * Return: 0 if the node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	return ((node && node->parent) ? 1 + binary_tree_depth(node->parent) : 0);
}
