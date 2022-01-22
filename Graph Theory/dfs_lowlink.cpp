/*

Cut Vertex(Articulation Points) : if this vertex is removed disconnects the graph.

Cut Edge(Bridge) : removing the edge disconnects the graph. Tree is a type of graph with all edge as cut edges


*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited_edge, visited_vertex, preorder_number, low_link, cut_vertex;
vector<pair<int, int>> cut_edge;
int number = 0;


int dfs(int parent, int current)
{
    // if(visited_edge[current] == 1)
    // {
    //     return preorder_number[current];
    // }
    number++;
    visited_edge[current] = 1;
    preorder_number[current] = number;
    low_link[current] = number;
    int count = 0;
    for(int i = 0; i < graph[current].size(); i++)
    {
        
        if(visited_edge[graph[current][i]] == 0)
        {
            int child_low_link = dfs(current, graph[current][i]);
            low_link[current] = min(low_link[current], child_low_link);
            count++;
        }
        else if(graph[current][i] != parent)
        {
            low_link[current] = min(preorder_number[graph[current][i]], low_link[current]);
        }
    }
    if(parent != current)
    {
        if(preorder_number[parent] < low_link[current])
        {
            cut_edge.push_back({parent, current});
        }
        if(low_link[current] >= preorder_number[parent])
        {
            cut_vertex.push_back(parent);
        }
    }
    else
    {
        if(count > 1)
        {
            cut_vertex.push_back(parent);
        }
    }
    return low_link[current];
}


int main()
{
    int n;
    cin >> n;
    graph.resize(n);
    int no_of_edges, v;
    preorder_number.resize(n);
    low_link.resize(n);
    visited_edge.resize(n, 0);
    visited_vertex.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_edges;
        for(int j = 0; j < no_of_edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }
    
    dfs(0,0);
    cout << "cut edge" << endl;
    for(int i = 0; i < cut_edge.size(); i++)
    {
        cout << cut_edge[i].first << " " << cut_edge[i].second << ", ";
    }
    cout << endl << "cut vertex " << endl;
    for(int i = 0; i < cut_vertex.size(); i++)
    {
        cout << cut_vertex[i] << ", ";
    }


}