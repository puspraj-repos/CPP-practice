#include<bits/stdc++.h>
using namespace std;

int root_at(int parent, int child,  vector<vector<int>> &graph, vector<int> &subtree, vector<int> &distance)
{
    int sum = 0;
    for(int i = 0; i < graph[child].size(); i++)
    {
        if(graph[child][i] != parent)
        {
            int ans= root_at(child, graph[child][i], graph, subtree, distance);
            sum += ans;
            distance[child] = distance[child] + distance[graph[child][i]] + ans;
        }
    }
    subtree[child] = 1 + sum;
    return subtree[child];
}

void find_distance(int parent, int child, vector<vector<int>> &graph, vector<int> &subtree, vector<int> &distance)
{
    for(int i = 0; i < graph[child].size(); i++)
    {
        if(graph[child][i] != parent)
        {
            distance[graph[child][i]] = distance[child] - distance[graph[child][i]] - subtree[graph[child][i]] + graph.size() - subtree[graph[child][i]] + distance[graph[child][i]];
            find_distance(child, graph[child][i], graph, subtree, distance);
        }
    }
}

void display(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main()
{
    int n, v, x;
    cin >> n;
    vector<int> subtree(n,0), distance(n, 0);
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        for(int j = 0; j < v; j++)
        {
            cin >> x;
            graph[i].push_back(x);
        }
    }
    root_at(0, 0, graph, subtree, distance);
    find_distance(0, 0, graph, subtree, distance);

    display(subtree);
    display(distance);

}