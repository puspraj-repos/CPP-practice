#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> previous;

pair<int, int> bfs_farthest(vector<vector<int>> graph, int node, int count)
{
    // if(visited[node] == 1)
    // {
    //     return {-1, node};
    // }
    int max_count = count, farthest_element = node;
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visited[graph[node][i]] == -1)
        {
            pair<int, int> temp = bfs_farthest(graph, graph[node][i], count + 1);
            if (max_count < temp.first)
            {
                max_count = temp.first;
                farthest_element = temp.second;
                previous[graph[node][i]] = node;
            }
        }
    }
    return {max_count, farthest_element};
}

void print_diameter(int start, int end)
{
    cout << end << "-->";
    while(previous[end] != start)
    {
        cout << previous[end] << "-->";
        end = previous[end];
    }
    cout << start << endl;
}

int main()
{

    int n, no_of_edges, v, node;
    cin >> n;
    graph.resize(n);
    visited.resize(n, -1);
    previous.resize(n, -1);
    // inserting into  graph
    cout << "for graph" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> no_of_edges;
        for (int j = 0; j < no_of_edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
        if (no_of_edges == 1)
        {
            node = i;
        }
    }

    pair<int, int> farthest = bfs_farthest(graph, node, 0);
    visited.assign(10, -1);
    
    pair<int, int> farthest2 = bfs_farthest(graph, farthest.second, 0);

    print_diameter(farthest.second, farthest2.second);

    cout << "Node :" << node << " Farthest 1:" << farthest.second << " Farthest 2:" << farthest2.second << endl;
}