#ifndef TREE_NODE_H
#define TREE_NODE_H


#include <vector>
#include <string>

struct TreeNode {
    char label;
    std::vector<TreeNode *> children;
    TreeNode(char l);
};

void add_child(TreeNode *parent, TreeNode *child);
void postorder(TreeNode *node, std::vector<TreeNode *> &nodes);
#endif // TREE_NODE_H
