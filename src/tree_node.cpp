#include "tree_node.h"

using namespace std;

TreeNode::TreeNode(char l) : label(l) {}

void add_child(TreeNode *parent, TreeNode *child)
{
    parent->children.push_back(child);
}


void postorder(TreeNode *node, std::vector<TreeNode *> &nodes)
{
    for (TreeNode *child : node->children)
    {
        postorder(child, nodes);
    }
    nodes.push_back(node);
}
