#include "binary_trees.h"

/**
 * binary_trees_ancestor - Retrieves the lowest common ancestor of two nodes.
 *
 * @node1: A pointer to the first node.
 * @node2: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor is found, the function should return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node1,
		const binary_tree_t *node2)
{
	binary_tree_t *parent1, *parent2;

	if (!node1 || !node2)
		return (NULL);
	if (node1 == node2)
		return ((binary_tree_t *)node1);

	parent1 = node1->parent;
	parent2 = node2->parent;

	if (node1 == parent2 || !parent1 || (!parent1->parent && parent2))
		return (binary_trees_ancestor(node1, parent2));
	else if (parent1 == node2 || !parent2 || (!parent2->parent && parent1))
		return (binary_trees_ancestor(parent1, node2));

	return (binary_trees_ancestor(parent1, parent2));
}
