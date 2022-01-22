#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

class edge_list
{
    public:
    int source, destination, weight;

    edge_list(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
    }
    edge_list(int u, int v)
    {
        source = u;
        destination = v;
        weight = 0;
    }
};

int main()
{
    int n, edges, u, v, w, source;
    cin >> n;

    cin >> edges;
    
    vector<edge_list> list;
    vector<int> distance_arr(n, INT_MAX/2);
    graph.resize(n);

    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        edge_list edge = edge_list(u,v,w);
        list.push_back(edge);
    }
    cin >> source;
    distance_arr[source] = 0;
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < list.size(); i++)
        {
            int temp = distance_arr[list[i].source] + list[i].weight;
            if(distance_arr[list[i].destination] > temp)
            {
                distance_arr[list[i].destination] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << distance_arr[i] << " ";
    }
    cout << endl;
}