#include<bits/stdc++.h> 
using namespace std;

vector<vector<int>> dp;


int maximum_points(int arr[][3], int state, int n)
{
    if(n == 0)
    {
        return arr[n][state];
    }
    if(dp[n][state] != -1)
    {
        return dp[n][state];
    }
    int max1 = INT_MIN, max2 = INT_MIN;
    if(state == 0)
    {
       max1 = maximum_points(arr, 1, n - 1);
       max2 = maximum_points(arr, 2, n - 1);
    }
    else if(state == 1)
    {
       max1 = maximum_points(arr, 0, n - 1);
       max2 = maximum_points(arr, 2, n-1);
    }
    else
    {
       max1 = maximum_points(arr, 0, n - 1);
       max2 = maximum_points(arr, 1, n - 1);
    }
    dp[n][state] = arr[n][state] + max(max1, max2);
    return dp[n][state];

}

int plus_one(int i, int j)
{
    return (i + j) % 3;
}

int main()
{
    int n;
    cin >> n;
    int arr[n][3];
    dp.resize(n);
    for(int i = 0; i < n; i++)
    {
        dp[i].resize(3, -1);
    }
    for(int i = 0; i < n; i++)
    {
        cin >>arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    // int max1 = maximum_points(arr, 0, n-1);
    // int max2 = maximum_points(arr, 1, n-1);
    // int max3 = maximum_points(arr, 2, n-1);
    //cout << max(max(max1, max2), max3);
    int dp2[n][3];
    dp2[0][0] = arr[0][0];
    dp2[0][1] = arr[0][1];
    dp2[0][2] = arr[0][2];
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int state = 0;
    for(int i = 1; i < n; i++)
    {
        dp2[i][0] = arr[i][0] + max(dp2[i - 1][1], dp2[i - 1][2]);
        dp2[i][1] = arr[i][1] + max(dp2[i - 1][2], dp2[i - 1][0]);
        dp2[i][2] = arr[i][2] + max(dp2[i - 1][0], dp2[i - 1][1]);
    }
    cout << max(max(dp2[n-1][0], dp2[n-1][1]), dp2[n-1][2]);

}