// bfs and dfs both have a time complexity of O(v+e)


#include<bits/stdc++.h>
using namespace std;

vector<int> visited(100, -1);

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

void print_graph(vector<int> *graph, int n)
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

void dfs(vector<int> *graph, int vertex, int color)
{
    if(visited[vertex] == -1)
    {
        visited[vertex] = color;
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if(visited[graph[vertex][i]]==-1)
            {
                dfs(graph, graph[vertex][i], color);
            }
        }
        
    }
}

void print_vector(vector<int> vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    
}


vector<int> *graph;

int main()
{
    int n;
    cout << "Enter the number of vertex\n";
    cin >> n;
    graph = new vector<int>[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the edges for vertex " << i << "\n";
        insert_in_graph(graph[i]);
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == -1)
        {
            dfs(graph, i, count);
        }
        else
        {
            count++;
        }
    }

    print_vector(visited, n);
    //print_graph(graph, n);
    
}