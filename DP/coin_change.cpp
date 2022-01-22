#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, int> dp;

int coin_change(vector<int> arr,int index, int sum, int s)
{
    if(sum == 0)
    {
        return 1;
    }
    if(sum < 0)
    {
        return 0;
    }
    if(index == s)
    {
        return 0;
    }
    if(dp.find({index, sum}) != dp.end())
    {
        return dp[{index, sum}];
    }
    int ans = 0;
    
    dp[{index, sum}] = coin_change(arr, index, sum - arr[index], s) + coin_change(arr, index + 1, sum, s);
    return dp[{index, sum}];
}

int main()
{
    int sum, n;
    cin >> sum >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = coin_change(arr, 0, sum, arr.size());
    cout << ans;

}