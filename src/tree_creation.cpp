#include "tree_creation.h"
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

// Função para gerar rótulos aleatórios de 1 a 4 caracteres variando de 'A' a 'Z'
void generateRandomLabels(vector<string>& labels, int n) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_device rd;

    while (labels.size() < n) {
        int label_length = rd() % 4 + 1;
        string label;
        for (int i = 0; i < label_length; ++i) {
            label += alphabet[rd() % 26];

        }
        if (find(labels.begin(), labels.end(), label) == labels.end()) {
            labels.push_back(label);
        }
    }
}

// Função para criar uma árvore n-ária balanceada com um número específico de nós
TreeNode* createNAryTree(int n) {
    if (n <= 0) return nullptr;

    vector<string> labels;
    generateRandomLabels(labels, n);

    TreeNode* root = new TreeNode(labels[0][0]);
    queue<TreeNode*> q;
    q.push(root);

    int label_index = 1;
    while (label_index < n) {
        TreeNode* current = q.front();
        q.pop();

        // Adiciona filhos ao nó atual
        for (int i = 0; i < 3 && label_index < n; ++i) {
            TreeNode* child = new TreeNode(labels[label_index++][0]);
            add_child(current, child);
            q.push(child);
        }
    }

    return root;
}


// Função para clonar uma árvore
TreeNode* cloneTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* new_root = new TreeNode(root->label);
    for (TreeNode* child : root->children) {
        add_child(new_root, cloneTree(child));
    }
    return new_root;
}

// Função para modificar ligeiramente uma árvore com base em uma porcentagem do tamanho da árvore
void modifyTree(TreeNode* root, int treeSize, float percentage) {
    if (root == nullptr || root->children.empty()) return;

    int numModifications = static_cast<int>(treeSize * percentage);
    if (numModifications < 1) numModifications = 1;

    random_device rd;

    for (int i = 0; i < numModifications; ++i) {
        if (root->children.size() > 1) {
            int idx1 = rd() % root->children.size();
            int idx2 = rd() % root->children.size();
            while (idx1 == idx2) {
                idx2 = rd() % root->children.size();
            }
            swap(root->children[idx1]->label, root->children[idx2]->label);
        }
    }

    // Aplica a modificação recursivamente em um filho aleatório
    if (!root->children.empty()) {
        int idx = rd() % root->children.size();
        modifyTree(root->children[idx], treeSize, percentage);
    }
}

// Função auxiliar para imprimir a árvore recursivamente com estrutura hierárquica
void printTreeHelper(TreeNode* node, int depth) {
    if (node == nullptr) return;
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << node->label << endl;
    for (TreeNode* child : node->children) {
        printTreeHelper(child, depth + 1);
    }
}

// Função para imprimir a árvore com estrutura hierárquica
void printTreeLevelOrder(TreeNode* root) {
    if (root == nullptr) return;
    printTreeHelper(root, 0);
}


