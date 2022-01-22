#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;


vector<int> top_sort(vector<vector<int>> graph, vector<int> in_degree)
{
    queue<int> no_dependencies;
    int no_of_nodes = in_degree.size();
    for(int i = 0; i < no_of_nodes; i++)
    {
        if(in_degree[i] == 0)
        {
            no_dependencies.push(i);
        }
    }
    vector<int> topsort;
    int count = no_dependencies.size();
    while(no_dependencies.empty() == false)
    {
        int node = no_dependencies.front();
        topsort.push_back(node);
        no_dependencies.pop();
        for(int i = 0; i < graph[node].size(); i++)
        {
            in_degree[graph[node][i]]--;
            if(in_degree[graph[node][i]] == 0)
            {
                no_dependencies.push(graph[node][i]);
            }
        }
    }
    if(topsort.size() != no_of_nodes)
    {
        cout << "Cycle detected";
    }
    return topsort;
}

void display_vector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int n, edges, v;
    cin>>n;
    graph.resize(n);
    vector<int> in_degree(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> edges;
        for(int j = 0; j < edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
            in_degree[v] += 1;
        }
    }

    vector<int> topsort = top_sort(graph, in_degree);

    display_vector(topsort);
}