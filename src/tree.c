#include "tree.h"

#include <stdlib.h>

TreeNode *tree_node_create(int value) {
    TreeNode *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void tree_destroy(TreeNode *root) {
    if (!root) return;
    tree_destroy(root->left);
    tree_destroy(root->right);
    free(root);
}

int tree_height(const TreeNode *root) {
    if (!root) return 0;
    int left = tree_height(root->left);
    int right = tree_height(root->right);
    return 1 + (left > right ? left : right);
}

int tree_sum(const TreeNode *root) {
    if (!root) return 0;
    return root->value + tree_sum(root->left) + tree_sum(root->right);
}

void tree_inorder(const TreeNode *root, int *out, int *index) {
    if (!root) return;
    tree_inorder(root->left, out, index);
    out[(*index)++] = root->value;
    tree_inorder(root->right, out, index);
}
