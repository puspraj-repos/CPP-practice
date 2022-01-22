#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;


void sssp_dijkstra(int starting_vertex, vector<int> &distance_array)
{
    // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > efficient;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > efficient;
    efficient.push({0, starting_vertex});
    distance_array[starting_vertex] = 0;
    while(efficient.empty() == false)
    {
        pair<int,int> node = efficient.top();
        efficient.pop();
        for(int i = 0; i < graph[node.second].size(); i++)
        {
            int temp = node.first + graph[node.second][i].second;
            if(distance_array[graph[node.second][i].first] > temp)
            {
                distance_array[graph[node.second][i].first] = temp;
                efficient.push({temp, graph[node.second][i].first});
            }
        }
    }
}

void display_vector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; 
    cin >> n;
    graph.resize(n);
    
    int edges;
    cin >> edges;

    int u, v, w;
    for(int i = 0 ; i < edges ;i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    int starting_vertex;
    cin >> starting_vertex;
    vector<int> distance_array(n, INT_MAX);
    sssp_dijkstra(starting_vertex, distance_array);
    display_vector(distance_array);
}