#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> visited;
vector<int> diameter;
// struct _tree
// {
//     int id;
//     vector<int> childs;
// };

// void root_the_tree_dfs(int root)
// {
//     if(visited[root] == 1)
//     {
//         return;
//     }
//     visited[root] = 1;
//     for(int i = 0; i < tree[root].size(); i++)
//     {
//         if(visited[tree[root][i]] == 0)
//         {

//         }
//     }
// }

void dfs_farthest_node(int id, int &farthest_node, int &distance,  int how_far, vector<int> &track)
{
    visited[id] = 1;
    if(distance < how_far)
    {
        distance = how_far;
        farthest_node = id;
    }
    for(int i = 0; i < tree[id].size(); i++)
    {
        if(visited[tree[id][i]] == 0)
        {
            dfs_farthest_node(tree[id][i], farthest_node, distance, how_far + 1, track);
            track[tree[id][i]] = id;
        }
    }
}


void find_diameter(int node)
{
    int farthest_node = node;
    int initial_distance = 0;
    vector<int> track(tree.size(), 0);
    dfs_farthest_node(node, farthest_node, initial_distance, 0, track);
    for(int i = 0; i < visited.size(); i++)
    {
        visited[i] = 0;
    }
    initial_distance = 0;
    dfs_farthest_node(farthest_node, farthest_node, initial_distance, 0, track);
    cout << farthest_node << " ";
    for(int i = 0; i < initial_distance; i++)
    {
        farthest_node = track[farthest_node];
        cout << farthest_node << " ";
    }
    cout << endl;

    
}

int main()
{
    int n, no_of_nodes, node;
    cin >> n;
    tree.resize(n);
    visited.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_nodes;
        for(int j = 0; j < no_of_nodes; j++)
        {
            cin >> node;
            tree[i].push_back(node);
            tree[node].push_back(i);
        }
    }
    //root_the_tree_dfs(0);
    find_diameter(0);
}