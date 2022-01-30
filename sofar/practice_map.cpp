#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for(int i = 0; i < n; i++)
    {
        cin >> startTime[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> endTime[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    vector<pair<int, pair<int, int>>> end_to_start;
    for(int i = 0; i < n; i++)
    {
        end_to_start.push_back(make_pair(endTime[i], make_pair(startTime[i], profit[i])));
    }
    sort(end_to_start.begin(), end_to_start.end());
    
    map<int, int> dp;
    int current_profit = 0;
    for(int i = 0; i < n; i++)
    {
        map<int, int>::iterator it = dp.lower_bound(end_to_start[i].second.first);
        if(it == dp.end())
        {
            //cout << "hi" << endl;
            current_profit = current_profit + end_to_start[i].second.second;
            dp[end_to_start[i].first] = current_profit;
        }
        else if(it->first == end_to_start[i].second.first)
        {
            //cout << "hi" << endl;
            current_profit = max(current_profit, it->second + end_to_start[i].second.second);
            dp[end_to_start[i].first] = current_profit;
        }
        else
        {
            
            auto it2 = it;
            it--;
            if(it == dp.end() || it2 == it)
            {
                //cout << "hi" << endl;
                current_profit = max(end_to_start[i].second.second, current_profit);
                dp[end_to_start[i].first] = current_profit;
            }
            else
            {
                //cout << "hi" << endl;
                current_profit = max(end_to_start[i].second.second + it->second, current_profit);
                dp[end_to_start[i].first] = current_profit;
            }
        }
    }
    cout << current_profit << endl;
}