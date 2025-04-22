#include <iostream>
using namespace std;

void naiveSearch(string txt, string pat) {
    int n = txt.length(), m = pat.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string txt = "AABAACAADAABAABA", pat = "AABA";
    naiveSearch(txt, pat);
    return 0;
}
