#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> visited;
vector<int> nodes_count;

struct rooted_tree
{
    int id;
    vector<rooted_tree*> childs;
};

rooted_tree* create_node(int id)
{
    rooted_tree *node = new rooted_tree;
    node->id = id;
    return node;
}

int dfs(rooted_tree *root)
{
    visited[root->id] = 1;
    int sum = 1;
    for(int i = 0; i < tree[root->id].size(); i++)
    {
        if(visited[tree[root->id][i]] == 0)
        {
            rooted_tree* node = create_node(tree[root->id][i]);
            root->childs.push_back(node);
            sum += dfs(node);
        }
    }
    nodes_count[root->id] = sum;
    return nodes_count[root->id];
}

pair<int, int> centroid(rooted_tree *root)
{
    int node_id = root->id;
    int exclude = tree.size() - nodes_count[root->id];
    for(int i = 0; i < root->childs.size(); i++)
    {
        if(exclude < nodes_count[root->childs[i]->id])
        {
            exclude = nodes_count[root->childs[i]->id];
        }
    }

    for(int i = 0; i < root->childs.size(); i++)
    {
        auto ans = centroid(root->childs[i]);
        if(ans.first < exclude)
        {
            exclude = ans.first;
            node_id = ans.second;
        }
    }
    return {exclude, node_id};
}

rooted_tree* root_the_tree(int node)
{
    rooted_tree *root = create_node(node);
    dfs(root);
    return root;
}

void preorder(rooted_tree *root)
{
    cout << root->id << " ";
    for(int i = 0; i < root->childs.size(); i++)
    {
        preorder(root->childs[i]);   
    }
}

int main()
{
    int n, no_of_adjacent_nodes, adjacent_node;
    cin >> n;
    tree.resize(n);
    visited.resize(n, 0);
    nodes_count.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_adjacent_nodes;
        for(int j = 0; j < no_of_adjacent_nodes; j++)
        {
            cin >> adjacent_node;
            tree[i].push_back(adjacent_node);
            tree[adjacent_node].push_back(i);
        }
    }
    rooted_tree *root = root_the_tree(0);
    preorder(root);
    auto ans = centroid(root);
    cout << "centroid value " << ans.second << endl;
    cout << "centroid size " << ans.first << endl;
}