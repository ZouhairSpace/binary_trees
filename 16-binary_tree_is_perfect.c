#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *node);
int is_perfect_recursive(const binary_tree_t *node,
		size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *node);
unsigned char is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - Determines if a binary tree is perfect.
 *
 * @node: A pointer to the root node of the tree to check.
 *
 * Return: 0 if the node is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (is_perfect_recursive(node, depth(get_leaf(node)), 0));
}

/**
 * depth - Computes the depth of a given node in a binary tree.
 * @node: A pointer to the node to calculate the depth of.
 *
 * Return: The depth of the node.
 */
size_t depth(const binary_tree_t *node)
{
	return (node->parent != NULL ? 1 + depth(node->parent) : 0);
}

/**
 * get_leaf - Retrieves a leaf node from a binary tree.
 * @node: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *get_leaf(const binary_tree_t *node)
{
	if (is_leaf(node) == 1)
		return (node);
	return (node->left ? get_leaf(node->left) : get_leaf(node->right));
}

/**
 * is_perfect_recursive - Checks recursively if a binary tree is perfect.
 * @node: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: The level of the current node.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *node,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(node))
		return (level == leaf_depth ? 1 : 0);
	if (node->left == NULL || node->right == NULL)
		return (0);
	return (is_perfect_recursive(node->left, leaf_depth, level + 1) &&
		is_perfect_recursive(node->right, leaf_depth, level + 1));
}

/**
 * is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

