#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> node_sum;

class tree
{
public:
    int id;
    vector<tree *> childs;
};

tree *create_node(int id)
{
    tree *node = new tree;
    node->id = id;
    return node;
}

int bfs_tree(tree *root)
{
    if (visited[root->id] == 1)
    {
        return 0;
    }
    visited[root->id] = 1;
    int sum = 1;
    for (int i = 0; i < graph[root->id].size(); i++)
    {
        if (visited[graph[root->id][i]] == 0)
        {
            tree *temp = create_node(graph[root->id][i]);
            root->childs.push_back(temp);
            sum += bfs_tree(temp);
        }
    }
    node_sum[root->id] = sum;
    return sum;
}

tree *root_tree(int id)
{
    tree *root = create_node(id);
    bfs_tree(root);
    return root;
}

void tree_preorder(tree *root)
{
    if (root != NULL)
    {
        cout << root->id << " ";
    }
    for (int i = 0; i < root->childs.size(); i++)
    {
        tree_preorder(root->childs[i]);
    }
}

pair<int,int> tree_centroid(tree *root, int n)
{
    pair<int,int> ans ={n - node_sum[root->id], root->id};
    for(int i = 0; i < root->childs.size(); i++)
    {
        if(node_sum[root->childs[i]->id] > ans.first)
        {
            ans.first = node_sum[root->childs[i]->id];
        }
    }
    for(int i = 0; i < root->childs.size(); i++)
    {
        ans = min(ans, tree_centroid(root->childs[i], n));
    }
    return ans;
}


void print_vector(vector<int> v)
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
    visited.resize(n, 0);
    node_sum.resize(n,0);

    int u, v, edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    tree *root = root_tree(4);

    tree_preorder(root);
    cout << endl;
    pair<int,int> centroid = tree_centroid(root, n);

    print_vector(node_sum);
    cout << centroid.first << " " << centroid.second << endl;

}