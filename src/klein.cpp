#include "klein.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void eulerTour(TreeNode *node, std::string &eulerString)
{
    if (!node)
        return;
    eulerString += node->label;
    for (auto child : node->children)
    {
        eulerTour(child, eulerString);
    }
    // eulerString += ')';
}

int editDistance(const string &s, const string &t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Imprimir Matriz
    /*
        cout << endl
            << "      ";

        for (int i = 0; i <= m; ++i)
        {
            if (s[i - 1])
                cout << s[i - 1] << "  ";
        }
    */

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    // IMPRIMIR MATRIZ
    /*
        cout << endl
            << "   ";
        for (int i = 0; i <= m; i++)
        {
            cout << dp[i][0] << "  ";
        }
        cout << endl;
        for (int i = 1; i <= m; ++i)
        {
            cout << t[i - 1] << "  ";
            for (int j = 0; j <= n; ++j)
            {

                cout << hex << dp[i][j] << "  ";
            }
            cout << endl;
        }
    */
    return dp[m][n];
}


int treeEditDistance(TreeNode *root1, TreeNode *root2)
{
    string euler1, euler2;
    eulerTour(root1, euler1);
    eulerTour(root2, euler2);
    return editDistance(euler1, euler2);
}

void executaKlein(TreeNode *T1, TreeNode *T2)
{
    cout << "The edit distance from Klein algorithm: " << treeEditDistance(T1, T2) << endl;
}
