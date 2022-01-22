#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int,int>, int, hash_pair> dp;
//0 for negative and 1 for positive

int target_sum(vector<int> arr, int index, int sum, int target)
{
    if(index < 0)
    {
        if(sum == target)
        return 1;
        else return 0;
    }
    if(dp.find({index, sum}) == dp.end())
    {
        dp[{index, sum}] = target_sum(arr, index - 1, sum - arr[index], target) + target_sum(arr, index - 1, sum + arr[index], target);
    }
    return dp[{index, sum}];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int target;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> target;

    int ans = target_sum(arr, n-1, 0, target);
    cout << ans;
} 