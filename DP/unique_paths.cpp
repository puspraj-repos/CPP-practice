#include<bits/stdc++.h>
using namespace std;


int unique_paths(int i, int j, int row, int col, vector<vector<int>> &dp)
{
    if(i == row and j == col)
    {
        return 1;
    }
    if(i > row || j > col)
    {
        return 0;
    }
    if(dp[i][j]!= -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    ans += unique_paths(i + 1, j, row, col, dp);
    ans += unique_paths(i, j + 1, row, col, dp);
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m);
    for(int i = 0; i < m; i++)
    {
        dp[i].resize(n, -1);
    }
    int ans = unique_paths(0, 0, m - 1, n - 1, dp);
    cout << ans;
}