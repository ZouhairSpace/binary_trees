#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs pre-order traversal on a binary tree.
 *
 * @node: A pointer to the root node of the tree to traverse.
 * @action: A pointer to a function to execute on each node.
 */
void binary_tree_preorder(const binary_tree_t *node, void (*action)(int))
{
	if (node && action)
	{
		action(node->n);
		binary_tree_preorder(node->left, action);
		binary_tree_preorder(node->right, action);
	}
}

