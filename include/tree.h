#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *tree_node_create(int value);
void tree_destroy(TreeNode *root);
int tree_height(const TreeNode *root);
int tree_sum(const TreeNode *root);
void tree_inorder(const TreeNode *root, int *out, int *index);

#endif
