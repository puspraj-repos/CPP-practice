#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void insert_in_graph(vector<int> &vertex)
{
    int edges, edge;
    cout << "Enter the number of edges\n";
    cin >> edges;
    cout << "Enter the vertices separated by space\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> edge;
        vertex.push_back(edge);
    }
}

void print_graph(vector<vector<int>> graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "vertex " << i << ":";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
}

vector<vector<int>> convert_to_rooted_bfs(int node, int n)
{
    vector<int> visited(n,0);
    vector<vector<int>> tree(n);
    queue<int> nodes;
    nodes.push(node);
    while(nodes.empty() == false)
    {
        node = nodes.front();
        nodes.pop();
        if(visited[node] == 0)
        {
            visited[node] = 1;
            for(int i = 0; i < graph[node].size(); i++)
            {
                if(visited[graph[node][i]] == 0)
                {
                    tree[node].push_back(graph[node][i]);
                    nodes.push(graph[node][i]);
                }
            }
        }
    }
    return tree;
}

int main()
{
    int n;
    cout << "Enter the number of nodes \t";
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the edges for vectex " << i << "\t";
        insert_in_graph(graph[i]);
    }
    vector<vector<int>> tree = convert_to_rooted_bfs(3, 8);
    print_graph(graph, n);
    cout << "\n\n";
    print_graph(tree, n);
    
}