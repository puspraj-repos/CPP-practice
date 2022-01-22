#include <bits/stdc++.h>
using namespace std;

//abcde, ace
vector<vector<int>> dp;

int lcs(int i, int j, string a, string b)
{
    int max_lcs = 0, temp = 0;
    if(i < a.size() && j < b.size())
    {
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(a[i] == b[j])
        {
            temp = 1 + lcs(i + 1, j + 1, a, b);
        }
        if(max_lcs < temp) 
        {
            max_lcs = temp;
        }
        temp = lcs(i + 1, j, a, b);
        if(temp > max_lcs)
        {
            max_lcs = temp;
        }
        temp = lcs(i, j + 1, a, b);
        if(max_lcs < temp)
        {
            max_lcs = temp;
        }
        dp[i][j] = max_lcs;
        return max_lcs;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    dp.resize(a.size());
    for(int i = 0; i < a.size(); i++)
    {
        dp[i].resize(b.size(), -1);
    }
    int ans = lcs(0, 0, a, b);
    cout << ans;
}