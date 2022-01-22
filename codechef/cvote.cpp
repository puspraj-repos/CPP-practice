#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2)
{
    if (p1.first > p2.first)
    {
        return 1;
    }
    if (p1.first < p2.first)
    {
        return 0;
    }
    return p1.second < p2.second;
}

int main()
{
    unordered_map<string, int> chef, country;
    unordered_map<string, string> mapping;
    int n, m;
    string chef_name, country_name;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> chef_name >> country_name;
        mapping[chef_name] = country_name;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> chef_name;
        chef[chef_name]++;
        country[mapping[chef_name]]++;
    }
    vector<pair<int, string>> chef_winner, country_winner;
    for (unordered_map<string, int>::iterator i = chef.begin(); i != chef.end(); i++)
    {
        chef_winner.push_back({(*i).second, (*i).first});
    }
    for (unordered_map<string, int>::iterator i = country.begin(); i != country.end(); i++)
    {
        country_winner.push_back({(*i).second, (*i).first});
    }
    sort(chef_winner.begin(), chef_winner.end(), comp);
    sort(country_winner.begin(), country_winner.end(), comp);
    cout << country_winner[0].second << endl;
    cout << chef_winner[0].second << endl;
}