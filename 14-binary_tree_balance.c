#include "binary_trees.h"

/**
 * height - Measures height of a binary tree
 * @tree: Pointer to the node
 * Return: Height or 0
 */
int height(const binary_tree_t *tree)
{
    int left;
    int right;

    if (!tree)
        return (0);

    left = height(tree->left);
    right = height(tree->right);

    return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Pointer to root node
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (height(tree->left) - height(tree->right));
}
