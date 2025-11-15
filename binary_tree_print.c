#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_WIDTH 6

void binary_tree_print(const binary_tree_t *tree);
static int height(const binary_tree_t *tree);
static void print_level(const binary_tree_t *tree, int level, int indent_space);
static void print_spaces(int count);

void binary_tree_print(const binary_tree_t *tree)
{
    int h, i;

    if (!tree)
        return;

    h = height(tree);
    for (i = 1; i <= h; i++)
    {
        print_level(tree, i, PRINT_WIDTH * (h - i));
        printf("\n");
    }
}

static int height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    else
    {
        int l_height = height(tree->left);
        int r_height = height(tree->right);
        return (l_height > r_height) ? l_height + 1 : r_height + 1;
    }
}

static void print_level(const binary_tree_t *tree, int level, int indent_space)
{
    if (!tree)
        return;

    if (level == 1)
    {
        print_spaces(indent_space);
        printf("(%03d)", tree->n);
    }
    else if (level > 1)
    {
        print_level(tree->left, level - 1, indent_space);
