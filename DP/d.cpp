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

unordered_map<pair<int, int>, int, hash_pair> dp;

long long kp(vector<long long> weight, vector<long long> value, int capacity, int item)
{
    if(item < 0)
    {
        return 0;
    }
    long long max1 = -1, max2 = -1;
    if(dp.find({item, capacity}) != dp.end())
    {
        return dp[{item, capacity}];
    }
    if (capacity - weight[item] >= 0)
    {
        
        max1 = value[item] + kp(weight, value, capacity - weight[item], item - 1);
        max2 =  kp(weight, value, capacity, item - 1);
    }
    else 
    {
        max2 = kp(weight, value, capacity, item - 1);
    }
    if(max2 > max1)
    {
        dp[{item, capacity}] = max2;
    }
    else 
    {
        dp[{item, capacity}] = max1;
    }
    return dp[{item, capacity}];
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<long long> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << kp(weight, value, c, n - 1);

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j <= c; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }



}




// 20 40
// 2  4

// 40 20

// take 40,                                                                do not take

// take 20,                        do not take 20

// take 20, do not take 20

//     20      0


// for (int i = 0; i < n; i++)
// {
//     if(capacity - weight[i] >= 0)
//     {
//         dp[weight[i]][i] = value[i] + 
//     }
// }
