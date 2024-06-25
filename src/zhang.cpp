#include "zhang.h"
#include <algorithm>
#include <iostream>

using namespace std;

int forestdist(vector<TreeNode *> &T1, vector<TreeNode *> &T2, vector<vector<int>> &F)
{
    int m = T1.size();
    int n = T2.size();
    F.assign(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        F[i][0] = F[i - 1][0] + 1; // Deletion cost
    }

    for (int j = 1; j <= n; ++j)
    {
        F[0][j] = F[0][j - 1] + 1; // Insertion cost
    }

    //imprimir matriz
/*
    cout << endl
         << "      ";

    for (int i = 0; i < m; ++i)
    {
        if (T1[i])
            cout << T1[i] ->label << "  ";
    }
*/
    
    
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int cost = (T1[i - 1]->label == T2[j - 1]->label) ? 0 : 1;
            F[i][j] = min({F[i - 1][j] + 1,          // Deletion
                           F[i][j - 1] + 1,          // Insertion
                           F[i - 1][j - 1] + cost}); // Change
        }
    }

    //IMPRIMIR MATRIZ
    /*
    cout << endl
         << "   ";
    for (int i = 0; i <= m; i++)
    {
        cout << F[i][0] << "  ";
    }
    cout << endl;
    for (int i = 1; i <= m; ++i)
    {
        cout << T2[i - 1]->label << "  ";
        for (int j = 0; j <= n; ++j)
        {

            cout << hex << F[i][j] << "  ";
        }
        cout << endl;
    }
    */
    return F[m][n];
}


int treedist(TreeNode *T1, TreeNode *T2)
{
    vector<TreeNode *> T1_nodes, T2_nodes;
    postorder(T1, T1_nodes);
    postorder(T2, T2_nodes);

    vector<vector<int>> F;
    return forestdist(T1_nodes, T2_nodes, F);
}

void executaZhang(TreeNode *T1, TreeNode *T2)
{
    cout << "Tree Edit Distance from Zhang algorithm: " << treedist(T1, T2) << endl;
}
