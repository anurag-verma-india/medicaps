#include <iostream>
#include <vector>
using namespace std;

// Function to find the Longest Common Subsequence
string findLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    
    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Reconstruct LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    
    return lcs;
}

// Function to print the DP table
void printDPTable(vector<vector<int>>& dp, string X, string Y) {
    cout << "DP Table:" << endl;
    cout << "    ";
    for (char c : Y)
        cout << c << " ";
    cout << endl;
    
    for (int i = 0; i <= X.length(); i++) {
        if (i == 0)
            cout << "  ";
        else
            cout << X[i - 1] << " ";
        
        for (int j = 0; j <= Y.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";
    
    cout << "\nString X: " << X << endl;
    cout << "String Y: " << Y << endl;
    
    vector<vector<int>> dp(X.length() + 1, vector<int>(Y.length() + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= X.length(); i++) {
        for (int j = 1; j <= Y.length(); j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Print DP table
    printDPTable(dp, X, Y);
    
    // Find LCS
    string lcs = findLCS(X, Y);
    
    cout << "Length of LCS: " << lcs.length() << endl;
    cout << "LCS: " << lcs << endl;
    
    return 0;
}