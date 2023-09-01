#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *node);
int is_full_recursive(const binary_tree_t *node);

/**
 * binary_tree_is_full - Determines if a binary tree is full.
 *
 * @node: A pointer to the root node of the tree to check.
 *
 * Return: 0 if the node is NULL.
 */
int binary_tree_is_full(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (is_full_recursive(node));
}

/**
 * is_full_recursive - Checks recursively if a binary tree is full.
 *
 * @node: A pointer to the root node of the tree to check.
 *
 * Return: 0 if the node is not NULL, otherwise 1.
 */
int is_full_recursive(const binary_tree_t *node)
{
	if (node != NULL)
	{
		if ((node->left != NULL && node->right == NULL) ||
		    (node->left == NULL && node->right != NULL) ||
		    is_full_recursive(node->left) == 0 ||
		    is_full_recursive(node->right) == 0)
			return (0);
	}

	return (1);
}

