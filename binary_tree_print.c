#include <stdio.h>
#include "binary_trees.h"

/**
 * print_tree - recursive helper to print tree sideways
 * @tree: pointer to the current node
 * @space: current indentation level
 */
static void print_tree(const binary_tree_t *tree, int space)
{
    int i;

    if (tree == NULL)
        return;

    /* Increase indentation */
    space += 10;

    /* Print right child first */
    print_tree(tree->right, space);

    /* Print current node after spacing */
    printf("\n");
    for (i = 10; i < space; i++)
        putchar(' ');
    printf("%d\n", tree->n);

    /* Print left child */
    print_tree(tree->left, space);
}

/**
 * binary_tree_print - prints the binary tree
 * @tree: pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    print_tree(tree, 0);
}
