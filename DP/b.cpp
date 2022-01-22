#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), dp(n);
    dp[n-1] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = n-2; i >= 0; i--)
    {
        vector<int> temp(k, INT_MAX);
        int min_cost = temp[0];
        for(int j = 1; j <= k; j++)
        {
            if(i + j < n)
            {
                temp[j] = abs(arr[i] - arr[i+j]) + dp[i + j];
                if(min_cost > temp[j])
                {
                    min_cost = temp[j];
                }
            }
        }
        dp[i] = min_cost;
    }
    cout << dp[0];
}
