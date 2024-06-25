#ifndef KLEIN_H
#define KLEIN_H

#include "tree_node.h"


void eulerTour(TreeNode *node, std::string &eulerString);
int editDistance(const std::string &s, const std::string &t);
int treeEditDistance(TreeNode *root1, TreeNode *root2);
void executaKlein(TreeNode *T1, TreeNode *T2);

#endif // KLEIN_H
