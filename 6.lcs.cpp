#include <iostream>
#include <vector>
using namespace std;

int lcs(string X, string Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> L(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            L[i][j] = (X[i-1] == Y[j-1]) ? 1 + L[i-1][j-1] : max(L[i-1][j], L[i][j-1]);
    return L[m][n];
}

int main() {
    string X = "AGGTAB", Y = "GXTXAYB"; //default
    cout << "Length of LCS is " << lcs(X, Y);
    return 0;
}
