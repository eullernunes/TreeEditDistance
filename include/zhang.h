#ifndef ZHANG_H
#define ZHANG_H


#include "tree_node.h"
#include <vector>

int forestdist(std::vector<TreeNode *> &T1, std::vector<TreeNode *> &T2, std::vector<std::vector<int>> &F);
int treedist(TreeNode *T1, TreeNode *T2);
void executaZhang(TreeNode *T1, TreeNode *T2);

#endif // ZHANG_H
