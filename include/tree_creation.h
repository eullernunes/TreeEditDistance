#ifndef TREE_CREATION_H
#define TREE_CREATION_H


#include "tree_node.h"

TreeNode* createNAryTree(int n);
// Função para clonar uma árvore
TreeNode* cloneTree(TreeNode* root);


// Função para modificar ligeiramente uma árvore
void modifyTree(TreeNode* root, int treeSize, float percentage = 0.8);

// Função para imprimir a árvore em nível por nível (BFS)
void printTreeLevelOrder(TreeNode* root);

#endif // TREE_CREATION_H
