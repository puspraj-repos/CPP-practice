#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> visited;

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

class rooted_tree
{
public:
    int id;
    rooted_tree *parent;
    vector<rooted_tree *> child;
};

void convert_to_rooted_dfs(int node)
{
    if (visited[node] == -1)
    {
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); ++i)
        {
            if (visited[graph[node][i]] == -1)
            {
                // asisgning parent to a child
                tree[node].push_back(graph[node][i]);
                convert_to_rooted_dfs(graph[node][i]);
            }
        }
    }
}

rooted_tree *create_node(int item)
{
    rooted_tree *node = new rooted_tree();
    node->id = item;
    node->parent = NULL;
    return node;
}

void convert_to_rooted_tree(int n, rooted_tree *root)
{
    if (visited[n] != -1)
    {
        return;
    }
    visited[n] = 1;
    for (int i = 0; i < graph[n].size(); ++i)
    {
        if (visited[graph[n][i]] == -1)
        {
            rooted_tree *node = create_node(graph[n][i]);
            node->parent = root;
            root->child.push_back(node);
            convert_to_rooted_tree(graph[n][i], node);
        }
    }
}

void tree_dfs(rooted_tree *root)
{
    cout << root->id;
    for (int i = 0; i < root->child.size(); i++)
    {
        tree_dfs(root->child[i]);
    }
}

rooted_tree *root = NULL;

int main()
{
    int n;
    cout << "Enter the number of nodes \t";
    cin >> n;
    tree.resize(n);
    graph.resize(n);
    visited.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the edges for vectex " << i << "\t";
        insert_in_graph(graph[i]);
    }
    // convert_to_rooted_dfs(3);
    root = create_node(3);
    convert_to_rooted_tree(3, root);

    cout << "size\t" << root->child.size() << endl;

    print_graph(graph, n);
    cout << "\n\n";
    // print_graph(tree, n);

    tree_dfs(root);
}