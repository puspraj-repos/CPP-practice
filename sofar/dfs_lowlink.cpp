#include<bits/stdc++.h>
using namespace std;

namespace test
{
    void puspraj()
    {
        cout << "Nothing to return";
    }
}

vector<vector<int>> graph;
vector<int> preorder_num, low_link;
vector<int> cut_vertex;
vector<pair<int, int>> cut_edges;

int dfs(int parent, int current, int &number)
{
    // if(preorder_num[current] != -1)
    // {
    //     return preorder_num[current];
    // }
    preorder_num[current] = number;
    low_link[current] = number;
    number++;
    int count = 0;
    for(int i = 0; i < graph[current].size(); i++)
    {
        if(preorder_num[graph[current][i]] == -1)
        {
            int temp = dfs(current, graph[current][i], number);
            low_link[current] = min(low_link[current], temp);
            count++;
        }
        else if(graph[current][i] != parent)
        {
            low_link[current] = min(low_link[current], preorder_num[graph[current][i]]);
        }
    }
    if(low_link[current] > preorder_num[parent])
    {
        cut_edges.push_back({parent, current});
    }
    if(current == parent)
    {
        if(count > 1)
        {
            cut_vertex[current] = 1;
        }
        else
        {
            cut_vertex[current] = 0;
        }
    }
    else if(low_link[current] >= preorder_num[parent])
    {
        cut_vertex[parent] = 1;
    }
    return low_link[current];
}

void display_vector(vector<int> vec)
{
    cout <<endl;
    for(int i = 0; i  < vec.size(); i++)
    {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

void display_vector(vector<pair<int, int>> vec)
{
    cout << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << "[" << vec[i].first << ", " << vec[i].second << "], ";
    }
    cout << endl;
}


int main()
{
    int n, no_of_neighbours, neighbour;
    cin >> n;
    graph.resize(n);
    preorder_num.resize(n, -1);
    low_link.resize(n, 0);
    cut_vertex.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_neighbours;
        for(int j = 0; j < no_of_neighbours; j++)
        {
            cin >> neighbour;
            graph[i].push_back(neighbour);
        }
    }
    int number = 0;
    dfs(0, 0, number);
    display_vector(preorder_num);
    display_vector(low_link);
    display_vector(cut_vertex);
    display_vector(cut_edges);

}