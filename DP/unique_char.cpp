#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

string maximum_char(vector<string> s, string current, int len)
{
    unordered_map<int, int> temp_hash;
    if(len < 0)
    {
        return current;
    }
    int flag = 0;
    string ans = "";
    for(int i = 0; i < s[len].size(); i++)
    {
        if(temp_hash.find(s[len][i] - 97) == temp_hash.end())
        {
            temp_hash[s[len][i] - 97]++;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    int flag2 = 0;
    string temp1="", temp2="";
    if(flag == 0)
    {
        for(int i = 0; i < current.size(); i++)
        {
            if(temp_hash.find(current[i] - 97) != temp_hash.end())
            {
                flag2 = 1;
                break;
            }
        }
        if(flag2 == 0)
        {
            temp1 = maximum_char(s, current+s[len], len - 1);
        }
        temp2 = maximum_char(s, current, len - 1);
    }
    else
    {
        temp1 = maximum_char(s, current, len - 1);
    }
    if(temp1.size() > temp2.size())
    return temp1;
    else return temp2;
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n);
    vector<string> s;
    string temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        s.push_back(temp);
        dp[i].resize(26, 0);
    }
    cout << maximum_char(s, "", n-1);

}