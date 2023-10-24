#include<bits/stdc++.h>
using namespace std;

int moves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        dp[i][0] = 0;
    }

    for (int col = 1; col < n; col++) {
        for (int row = 0; row < m; row++) {
            int currentVal = grid[row][col];

            dp[row][col] = 0;

            for (int i = -1; i <= 1; i++) {
                int newRow = row + i;

                if (newRow >= 0 && newRow < m) {
                    dp[row][col] = max(dp[row][col], dp[newRow][col - 1] + (currentVal > grid[newRow][col - 1] ? 1 : 0));
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < m; i++) {
        max = max(max, dp[i][n - 1]);
    }

    return max;
}

int main() {
    vector<vector<int>> grid1 = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    vector<vector<int>> grid2 = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};

    cout << moves(grid1) << endl; 
    cout << moves(grid2) << endl; 
    return 0;
}
