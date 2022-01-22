#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<int> find_center(vector<vector<int>> graph)
{
    // calculating degree
    int n = graph.size();
    vector<int> degree(n,0);
    vector<int> leaves;
    for(int i = 0; i < n; i++)
    {
        degree[i] = graph[i].size();
        if(degree[i] <= 1)
        {
            leaves.push_back(i);
        }
    }
    int count = leaves.size();

    while (count < n)
    {
        vector<int> new_leaves;
        for(int i = 0; i < leaves.size(); i++)
        {
            for(int j = 0; j < graph[leaves[i]].size(); j++)
            {
                degree[graph[leaves[i]][j]] -= 1;
                if(degree[graph[leaves[i]][j]] == 1)
                {
                    new_leaves.push_back(graph[leaves[i]][j]);
                }
            }
            //removing the leaf node
            degree[leaves[i]] = 0;
        }
        leaves = new_leaves;
        count += leaves.size();
    }

    return leaves;
    // for indexes where degree is 1 (leaf nodes)    
}

int main()
{
    int n,edges,v;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges;
        for(int j = 0; j < edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }

    auto tree_center = find_center(graph);
    cout << "Centers : \n";
    for(auto &i : tree_center)
    {
        cout << i << " ";
    }
}