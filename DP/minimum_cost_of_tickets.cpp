#include <bits/stdc++.h>
using namespace std;

int day1, day7, day30;
map<pair<int, int>, int> dp;
int minimum_cost(vector<int> days, int validity, int current, int n)
{
    if(current > n)
    {
        return 0;
    }
    if(dp.find({validity, current}) != dp.end())
    {
        return dp[{validity, current}];
    }
    int ans = INT_MAX;
    if(validity >= days[current])
    {
        ans = minimum_cost(days, validity, current + 1, n);
    }
    int one = day1 + minimum_cost(days, days[current], current + 1, n);
    int seven = day7 + minimum_cost(days, days[current] + 6, current + 1, n);
    int thirty = day30 + minimum_cost(days, days[current] + 29, current + 1, n);
    dp[{validity, current}] = min(min(min(one, seven), thirty), ans);
    return dp[{validity, current}];
}

int main()
{
    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++)
    {
        cin>> days[i];
    }
    
    cin >> day1 >> day7 >> day30;

    int ans = minimum_cost(days, days[0] - 1, 0, n-1);
    int ans;
    cout << ans;

    // int dp[n] = {0};
    // for(int i = n-1; i >= 0; i--)
    // {
    //     days[i] = min()
    // }

}