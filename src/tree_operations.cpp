#include <iostream>
#include <chrono>
#include "tree_operations.h"

using namespace std;
using namespace std::chrono;


void measureExecutionTime(TreeNode *root1, TreeNode *root2)
{
    cout << "------------------------------" << endl;

    high_resolution_clock::time_point inicio, fim;
    long duracao;

    // Medindo tempo de execução de Zhang
    inicio = high_resolution_clock::now();
    executaZhang(root1, root2);
    fim = high_resolution_clock::now();
    duracao = duration_cast<microseconds>(fim - inicio).count();
    cout << "Tempo de execução Zhang: " << duracao << " microssegundos" << endl;

    // Medindo tempo de execução de Klein
    inicio = high_resolution_clock::now();
    executaKlein(root1, root2);
    fim = high_resolution_clock::now();
    duracao = duration_cast<microseconds>(fim - inicio).count();
    cout << "Tempo de execução Klein: " << duracao << " microssegundos" << endl;

    cout << "------------------------------" << endl;
}

void deleteTree(TreeNode *node)
{
    if (!node)
        return;
    for (auto child : node->children)
    {
        deleteTree(child);
    }
    delete node;
}