#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> visited;

struct rooted_tree
{
    int node;
    rooted_tree * parent;
    vector<rooted_tree*> child;
};

void root_the_tree(int root_node)
{
    // int graph_size = graph.size();
    // vector<int> outdegree(graph_size, 0);

    // for(int iterator = 0; iterator < graph_size; iterator++)
    // {
    //     outdegree[iterator] = graph[iterator].size();
    // }
    if(visited[root_node] == 1)
    {
        return;
    }
    visited[root_node] = 1;
    for(int iterator = 0; iterator < graph[root_node].size(); iterator++)
    {
        if(visited[graph[root_node][iterator]] == 0)
        {
            root_the_tree(graph[root_node][iterator]);
            tree[root_node].push_back(graph[root_node][iterator]);
        }
    }    
}

void root_using_bfs(int root_node)
{
    queue<int> nodes;
    nodes.push(root_node);
    while(nodes.empty() == false)
    {
        int temp_node = nodes.front();
        nodes.pop();
        if(visited[temp_node] == 0)
        {
            visited[temp_node] = 1;
            for(int i = 0; i < graph[temp_node].size(); i++)
            {
                if(visited[graph[temp_node][i]] == 0)
                {
                    tree[temp_node].push_back(graph[temp_node][i]);
                    nodes.push(graph[temp_node][i]);
                }
            }
        }
    }
}




void inorder(int root)
{
    cout << root << " ";
    for(int i = 0; i < tree[root].size(); i++)
    {
        inorder(tree[root][i]);
    }
}

int main()
{
    int num_of_nodes, num_of_neighbours, node;
    cin >> num_of_nodes;
    visited.resize(num_of_nodes, 0);
    graph.resize(num_of_nodes);
    tree.resize(num_of_nodes);
    for(int iterator = 0; iterator < num_of_nodes; iterator++)
    {
        cin >> num_of_neighbours;
        for(int neighbour_iterator = 0; neighbour_iterator < num_of_neighbours; neighbour_iterator++)
        {
            cin >> node;
            graph[iterator].push_back(node);
        }
    }
    int root_node=1;
    //root_the_tree(root_node);
    root_using_bfs(root_node);
    inorder(root_node);
}