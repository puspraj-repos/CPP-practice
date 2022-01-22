#include<bits/stdc++.h>
# define mod 1000000007
using namespace std;

struct hash_pair
{
    template<typename A, typename B>
    size_t operator ()(const pair<A, B> &p) const
    {
        auto hash1 = hash<A>{}(p.first);
        auto hash2 = hash<B>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> dp;

int dice_roll(int d, int f, int t)
{
    if(d == 0 and t ==0)
    {
        return 1;
    }
    else if(d ==0 or t < 0)
    {
        return 0;
    }
    if(dp.find({d, t}) != dp.end())
    {
        return dp[{d, t}];
    }
    int ans = 0;

        
        for(int j = 1; j <= f; j++)
        {
            ans = (ans + dice_roll(d - 1, f, t - j))%mod;
        }
    dp[{d, t}] = ans;
    return ans;
}

int main()
{
    int d, f , t;
    cin >> d >> f >> t;
    auto ans = dice_roll(d, f, t);
    cout << ans;
}