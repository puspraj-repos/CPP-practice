#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int find_center()
{
    vector<int> degree(graph.size(), 0);
    vector<int> leaves;
    for(int i = 0; i < graph.size(); i++)
    {
        degree[i] = graph[i].size();
        if(degree[i] == 1 || degree[i] == 0)
        {
            leaves.push_back(i);
        }
    }
    int count = leaves.size();
    while(count < graph.size())
    {
        vector<int> new_leaves;
        for(int i = 0; i < leaves.size(); i++)
        {
            for(int j = 0; j < graph[leaves[i]].size(); j++)
            {
                degree[graph[leaves[i]][j]]--;
                if(degree[graph[leaves[i]][j]] == 1)
                {
                    new_leaves.push_back(graph[leaves[i]][j]);
                }
            }
        }
        count+=new_leaves.size();
        leaves = new_leaves;
    }
    for(int i = 0; i < leaves.size(); i++)
    {
        cout << leaves[i] << " ";
    }
    return leaves[0];
}


int main()
{
    int n, v;
    cin >> n;
    graph.resize(n);
    int adjacent;
    for(int i = 0; i < n; i++)
    {
        cin >> adjacent;
        for(int j = 0; j < adjacent; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }

    int center = find_center();
    
}