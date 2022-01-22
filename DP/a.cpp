#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int min_cost(vector<int> arr, int current)
{
    int min1 = INT_MAX, min2 = INT_MAX;
    if (current >= arr.size())
    {
        return 0;
    }
    if (dp[current] != -1)
    {
        return dp[current];
    }
    if (current + 1 < arr.size())
    {
        min1 = abs(arr[current] - arr[current + 1]) + min_cost(arr, current + 1);
    }
    if (current + 2 < arr.size())
    {
        min2 = abs(arr[current] - arr[current + 2]) + min_cost(arr, current + 2);
    }
    dp[current] = min(min1, min2);
    return min(min1, min2);
}


int main()
{
    int n;
    cin >> n;
    dp.resize(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = -1;
    }
    dp[n-1] =0;

    int temp1, temp2;
    for(int i = n-2; i >= 0; i--)
    {
        temp1 = INT_MAX, temp2 = INT_MAX;
        if(i + 1 < n)
        {
            temp1 = abs(arr[i] - arr[i + 1]) + dp[i + 1];
        }
        if(i + 2 < n)
        {
            temp2 = abs(arr[i] - arr[i + 2]) + dp[i + 2];
        }
        dp[i] = min(temp1, temp2);
    }

    cout << dp[0];
}