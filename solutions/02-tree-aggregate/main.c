#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static TreeNode *read_tree(void) {
    int value;
    if (scanf("%d", &value) != 1) return NULL;
    if (value == -1) return NULL;
    TreeNode *node = tree_node_create(value);
    if (!node) exit(1);
    node->left = read_tree();
    node->right = read_tree();
    return node;
}

static void print_inorder(const TreeNode *root) {
    int values[1024];
    int index = 0;
    tree_inorder(root, values, &index);
    for (int i = 0; i < index; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
}

int main(void) {
    TreeNode *root = read_tree();
    printf("height=%d\n", tree_height(root));
    printf("sum=%d\n", tree_sum(root));
    printf("inorder=");
    print_inorder(root);
    tree_destroy(root);
    return 0;
}
