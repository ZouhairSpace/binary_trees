#include "binary_trees.h"

/**
 * binary_tree_inorder - Executes in-order traversal on a binary tree.
 *
 * @node: A pointer to the root node of the tree to traverse.
 * @action: A pointer to a function to perform on each node.
 */
void binary_tree_inorder(const binary_tree_t *node, void (*action)(int))
{
	if (node && action)
	{
		binary_tree_inorder(node->left, action);
		action(node->n);
		binary_tree_inorder(node->right, action);
	}
}

