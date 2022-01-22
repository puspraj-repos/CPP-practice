#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;
int len = 0;
int max_profit(int current, int fee, int budget, vector<int> &prices)
{
    if(current == len)
    {
        return 0;
    }
    if(dp.find({current, budget}) != dp.end())
    {
        return dp[{current, budget}];
    }
    int traded=0, not_traded=0, not_traded_2 = 0;
    if(budget + fee < prices[current])
    {
        traded = prices[current] - budget - fee + max_profit(current + 1, fee, prices[current], prices);
    }
    not_traded = max_profit(current + 1, fee, budget, prices);
    not_traded_2 = max_profit(current + 1, fee, prices[current], prices);
    traded = max(traded, not_traded);
    traded = max(traded, not_traded_2);
    dp[{current, budget}] = traded;
    return traded;
}

int main()
{
    int n;
    cin >> n;
    len = n;
    int fee;
    cin >> fee;
    vector<int> prices(n);
    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int ans = max_profit(0, fee, 60000, prices);
    cout << ans;
}