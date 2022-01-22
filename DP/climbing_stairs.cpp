#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

int climbing_stairs(long long n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    if(dp[n] == -1)
    {  
        dp[n] = climbing_stairs(n - 1) + climbing_stairs(n - 2);
    }
    return dp[n];
}


int main()
{
    long long n;
    cin>> n;
    // dp.resize(n + 1, -1);
    int first = 1, second = 2, ans;
    for(int i = 3; i <= n; i++)
    {
        ans = first + second;
        first = second;
        second = ans;
    }
}