#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dp;

pair<int,int> coin_change(vector<int> arr, int target)
{
    if(target == 0)
    {
        return {1,0};
    }
    if(dp[target].first != -1)
    {
        return dp[target];
    }
    int min_coins = INT_MAX/2;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= target)
        {
            auto temp = coin_change(arr, target - arr[i]);
            if(temp.first == 1 and temp.second + 1 < min_coins)
            {
                min_coins = temp.second + 1;
            }
        }  
    }
    if(min_coins != INT_MAX/2)
    {
        dp[target] = {1,min_coins};
        return dp[target];
    }
    else
    {
        dp[target] = {0, min_coins};
        return dp[target];
    }
}

int main()
{
    int n, target;
    cin >> n >> target;
    dp.resize(target+1, {-1, 0});
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
    cin >> coins[i];
    pair<int,int> ans = coin_change(coins, target);
    if(ans.first == 0)
    {
        cout << -1;
    }
    else 
    {
        cout << ans.second << endl;
    }
}