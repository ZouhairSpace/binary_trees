#include "binary_trees.h"

/**
 * binary_tree_postorder - Executes post-order traversal on a binary tree.
 *
 * @node: A pointer to the root node of the tree to traverse.
 * @action: A pointer to a function to execute on each node.
 */
void binary_tree_postorder(const binary_tree_t *node, void (*action)(int))
{
	if (node && action)
	{
		binary_tree_postorder(node->left, action);
		binary_tree_postorder(node->right, action);
		action(node->n);
	}
}

