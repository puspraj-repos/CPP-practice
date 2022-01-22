// bfs is really useful when we need to find the shortest path in unweighted graph

#include<bits/stdc++.h>
using namespace std;

vector<int> visited(100, -1);
vector<int> previous(100, -1);

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

void bfs(vector<vector<int>> graph, int vertex)
{
    queue<int> nodes;
    int count = 0;
    nodes.push(vertex);
    int temp_vertex;
    while(nodes.empty() == false)
    {
        temp_vertex = nodes.front();
        if(visited[temp_vertex] == -1)
        {
            visited[temp_vertex] = count;
        }
        nodes.pop();
        for (int i = 0; i < graph[temp_vertex].size(); i++)
        {
            if(visited[graph[temp_vertex][i]] == -1)
            {
                nodes.push(graph[temp_vertex][i]);
                if(previous[graph[temp_vertex][i]] == -1)
                {
                    previous[graph[temp_vertex][i]]=temp_vertex;
                }
            }
        }
    }
}

void print_vector(vector<int> visited, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << visited[i] << " ";
    }
}

void reconstruct(vector<int> previous, int i, int j)
{
    cout << "The path from "<< i << " to " << j << " is ";
    stack<int> path;
    while(previous[j] != 0 and previous[j] != -1)
    {
        path.push(previous[j]);
        j = previous[j];
    }
    cout << 0 << "-->";
    while(path.empty() == false)
    {
        cout << path.top() << "-->";
        path.pop();
    }
    cout << endl;
}

vector<vector<int>> graph;

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

    for (int i = 0; i < n; i++)
    {
        if(visited[i] == -1)
        {
            bfs(graph, i);
        }
    }
    print_graph(graph, n);
    print_vector(visited, n);

    for (int i = 0; i < n; i++)
    {
        cout << previous[i] << " ";
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j)
            {
                reconstruct(previous, i, j);
            }
        }
        
    }
    

}