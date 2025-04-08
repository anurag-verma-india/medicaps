#include <iostream>
#include <vector>
using namespace std;

int knapsack01(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // Fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If current item weight is more than capacity w, 
            // we can't include this item
            if (weights[i-1] > w)
                dp[i][w] = dp[i-1][w];
            else
                // Choose maximum of including or excluding the item
                dp[i][w] = max(
                    dp[i-1][w],                                  // Exclude item
                    values[i-1] + dp[i-1][w-weights[i-1]]        // Include item
                );
        }
    }
    
    // Display the solution table (optional)
    cout << "DP Table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++)
            cout << dp[i][w] << "\t";
        cout << endl;
    }
    
    return dp[n][W];
}

int main() {
    int W = 50;  // Knapsack capacity
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = values.size();
   
    cout << "\nItems (value, weight):" << endl;
    for (int i = 0; i < n; i++)
        cout << "Item " << i+1 << ": (" << values[i] << ", " << weights[i] << ")" << endl;
    
    cout << "\nKnapsack capacity: " << W << endl;
    
    int maxValue = knapsack01(W, weights, values, n);
    cout << "\nMaximum value that can be obtained: " << maxValue << endl;
    
    return 0;
}