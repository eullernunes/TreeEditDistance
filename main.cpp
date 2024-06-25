#include "tree_node.h"
#include "tree_creation.h"
#include "tree_operations.h"
#include <iostream>

using namespace std;


int main()
{
    int sizes[] = {10, 100, 500, 1000, 5000, 10000};
    for (int size : sizes)
    {

        TreeNode *tree1 = createNAryTree(size);
        TreeNode *tree2 = cloneTree(tree1);
        
        modifyTree(tree2, size);
        
        cout << endl;
        cout << "Arvore tamanho :" << size << " " << endl;
        measureExecutionTime(tree1, tree2);
        
        deleteTree(tree1);
        deleteTree(tree2);
    }

    return 0;
}
