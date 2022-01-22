#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, graph2;

class tree
{
public:
    tree *parent;
    int id;
    vector<tree *> childs;
};

vector<int> center_of_tree(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> degrees(n, 0);
    // counting degree of each node in a tree

    vector<int> leaves;

    for (int i = 0; i < n; i++)
    {
        degrees[i] = graph[i].size();
        if (degrees[i] <= 1)
        {
            leaves.push_back(i);
        }
    }

    int count = leaves.size();

    while (count < n)
    {
        vector<int> new_leaves;
        for (int i = 0; i < leaves.size(); i++)
        {
            // decrement the degree of it's neighbours.
            for (int j = 0; j < graph[leaves[i]].size(); j++)
            {
                degrees[graph[leaves[i]][j]] -= 1;
                if (degrees[graph[leaves[i]][j]] == 1)
                {
                    new_leaves.push_back(graph[leaves[i]][j]);
                }
            }
            degrees[leaves[i]] = 0;
        }
        leaves = new_leaves;
        count += leaves.size();
    }
    return leaves;
}

// tree functions

tree *create_node(int id)
{
    tree *node = new tree;
    node->id = id;
    node->parent = NULL;
    return node;
}

void dfs_tree(tree *root, vector<vector<int>> graph, vector<int> visited)
{
    if (visited[root->id] != 0)
    {
        return;
    }
    visited[root->id] = 1;
    for (int i = 0; i < graph[root->id].size(); i++)
    {
        if (visited[graph[root->id][i]] == 0)
        {
            tree *node = create_node(graph[root->id][i]);
            node->parent = root;
            root->childs.push_back(node);
            dfs_tree(node, graph, visited);
        }
    }
}

tree *root_tree(vector<vector<int>> graph, int node)
{
    tree *root = create_node(node);
    vector<int> visited(graph.size(), 0);
    dfs_tree(root, graph, visited);
    return root;
}

string encoding(tree *root)
{
    vector<string> arr;
    string temp = "";

    for (int i = 0; i < root->childs.size(); i++)
    {
        arr.push_back(encoding(root->childs[i]));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        temp += arr[i];
    }
    return "(" + temp + ")";
}

bool is_isomorphic(vector<vector<int>> graph, vector<vector<int>> graph2)
{
    vector<int> center_tree1 = center_of_tree(graph);
    tree *tree1 = root_tree(graph, center_tree1[0]);
    string encode1 = encoding(tree1);
    cout << encode1;
    vector<int> center_tree2 = center_of_tree(graph2);

    for (int i = 0; i < center_tree2.size(); i++)
    {
        if (encoding(root_tree(graph2, center_tree2[i])) == encode1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, no_of_edges, v;
    cin >> n;
    graph.resize(n);
    graph2.resize(n);
    // inserting into first graph
    cout << "for graph 1" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> no_of_edges;
        for (int j = 0; j < no_of_edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }
    cout << "For graph 2" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> no_of_edges;
        for (int j = 0; j < no_of_edges; j++)
        {
            cin >> v;
            graph2[i].push_back(v);
        }
    }

    bool isomorphic = is_isomorphic(graph, graph2);

    cout << isomorphic << endl;
}