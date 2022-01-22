#include<bits/stdc++.h>
using namespace std;

int total_possibilities(vector<int> &nums,int current_value, int current, int len, int target, map<pair<int,int>, int> &dp)
    {
        if(current==len)
        {
            if(target==current_value)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        if(dp.find({target,current})== dp.end())
        {
            dp[{current_value,current}]= total_possibilities(nums, current_value+nums[current], current+1, len, target, dp) + total_possibilities(nums, current_value-nums[current], current+1, len, target, dp);
            return dp[{current_value, current}];
        }
        else return dp[{current_value, current}];
    }

int main()
{
    int target;
    
    int n;
    cin>> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin>> nums[i];
    }
    map<pair<int,int>, int> dp;
    int ans = total_possibilities(nums,0,0,nums.size(), target, dp);
    cout << ans << endl;  
}