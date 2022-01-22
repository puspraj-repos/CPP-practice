#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> graph;
vector<int> visited;
stack<int> temp;

void top_sort(vector<vector<int>> graph, int node)
{
    if(visited[node] != 0)
    {
        return;
    }
    visited[node] = 1;
    temp.push(node);
    for(int i = 0; i < graph[node].size(); i++)
    {
        if(visited[graph[node][i]] == 0)
        {
            top_sort(graph, graph[node][i]);
        }
    }

}

int main()
{
    int n;
    cin >> n;

    graph.resize(n);

    int edges, v;

    for(int i = 0; i < n; i++)
    {
        cin>> edges;

        for(int j = 0; j < edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }
    vector<int>topsort(n);
    visited.resize(n, 0);
    int node_count = n-1;
    for(int i = 0; i < n; i++)
    {
        top_sort(graph, i);
        while(temp.empty() == false)
        {
            topsort[node_count] = temp.top();
            temp.pop();
            node_count--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << topsort[i] << " ";
    }    

}