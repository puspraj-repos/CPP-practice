#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> height;
int preorder_num = 0;

class tree
{
public:
    int id;
    vector<tree *> childs;
};

vector<int> find_center(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> degree(n);
    vector<int> leaves;

    for (int i = 0; i < n; i++)
    {
        degree[i] = graph[i].size();
        if (degree[i] <= 1)
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
            for (int j = 0; j < graph[leaves[i]].size(); j++)
            {
                degree[graph[leaves[i]][j]] -= 1;
                if (degree[graph[leaves[i]][j]] == 1)
                {
                    new_leaves.push_back(graph[leaves[i]][j]);
                }
            }
            degree[leaves[i]] = 0;
        }
        leaves = new_leaves;
        count += leaves.size();
    }
    return leaves;
}

tree *create_node(int id)
{
    tree *node = new tree();
    node->id = id;
    return node;
}

void dfs(tree *root, vector<vector<int>> graph)
{
    if (visited[root->id] != -1)
    {
        return;
    }
    visited[root->id] = 1;
    for (int i = 0; i < graph[root->id].size(); i++)
    {
        if (visited[graph[root->id][i]] == -1)
        {
            tree *temp = create_node(graph[root->id][i]);
            root->childs.push_back(temp);
            dfs(temp, graph);
        }
    }
}

tree *root_the_tree(vector<vector<int>> graph, int id)
{

    tree *root = create_node(id);

    dfs(root, graph);
    return root;
}

void assign_preorder_num(tree *root, vector<int> &node_hash, vector<int> &reverse_lookup, vector<int> &height, int level)
{
    node_hash[root->id] = preorder_num++;
    reverse_lookup.push_back(root->id);
    height.push_back(level);
    for (int i = 0; i < root->childs.size(); i++)
    {
        assign_preorder_num(root->childs[i], node_hash, reverse_lookup, height, level + 1);
        node_hash[root->id] = preorder_num++;
        reverse_lookup.push_back(root->id);
        height.push_back(level);
    }
}

void bfs_traversal(tree *root)
{
    cout << root->id << " ";
    for (int i = 0; i < root->childs.size(); i++)
    {
        bfs_traversal(root->childs[i]);
    }
}

void compute_sparse_table(vector<vector<int>> &sparse_table, vector<vector<int>> &sparse_table_index, vector<int> height)
{
    int sparse_table_size = sparse_table.size();
    int height_size = height.size();
    for (int i = 0; i < height_size; i++)
    {
        sparse_table_index[0].push_back(i);
        sparse_table[0].push_back(height[i]);
    }
    for (int i = 1; i < sparse_table_size; i++)
    {
        for (int j = 0; j < height_size; j++)
        {
            int offset = 1 << (i - 1);
            if (offset + j >= height_size)
            {
                offset = height_size - 1 - j;
            }
            if (sparse_table[i - 1][j] <= sparse_table[i - 1][j + offset])
            {
                sparse_table[i].push_back(sparse_table[i - 1][j]);
                sparse_table_index[i].push_back(sparse_table_index[i - 1][j]);
            }
            else
            {
                sparse_table[i].push_back(sparse_table[i - 1][j + offset]);
                sparse_table_index[i].push_back(sparse_table_index[i - 1][j + offset]);
            }
        }
    }
}

void display_sparse_table(vector<vector<int>> sparse_table)
{
    int sparse_table_size = sparse_table.size();
    int length = sparse_table[0].size();

    for (int i = 0; i < sparse_table_size; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << sparse_table[i][j] << " ";
        }
        cout << endl;
    }
}

int lca(int node1, int node2, vector<int> node_hash, vector<int> reverse_lookup, vector<vector<int>> sparse_table, vector<vector<int>> sparse_table_index)
{
    int hash1 = node_hash[node1] <= node_hash[node2] ? node_hash[node1] : node_hash[node2];
    int hash2 = node_hash[node1] >= node_hash[node2] ? node_hash[node1] : node_hash[node2];

    int diff = hash2 - hash1 + 1;
    int ans = -1;

    int base2 = log2(diff);
    int offset = hash2 - (1 << base2) + 1;
    if(sparse_table[base2][hash1] > sparse_table[base2][offset])
    {
        ans = sparse_table_index[base2][offset];
    }
    else 
    {
        ans = sparse_table_index[base2][hash1];
    }
    
    if(ans != -1)
    {
        return reverse_lookup[ans];
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, edges, v;
    cin >> n;
    graph.resize(n);
    visited.resize(n, -1);
    height.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> edges;
        for (int j = 0; j < edges; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }
    int center = find_center(graph)[0];

    tree *root = root_the_tree(graph, center);

    vector<int> node_hash(n);

    vector<int> height, reverse_lookup;

    assign_preorder_num(root, node_hash, reverse_lookup, height, 1);

    for (int i = 0; i < preorder_num; i++)
    {
        cout << reverse_lookup[i] << ", " << height[i] << ", " << i << endl;
    }
    const int sparse_table_size = log2(preorder_num - 1) + 1;
    vector<vector<int>> sparse_table(sparse_table_size);
    vector<vector<int>> sparse_table_index(sparse_table_size);
    compute_sparse_table(sparse_table, sparse_table_index, height);

    cout << "Sparse table : \n";
    display_sparse_table(sparse_table);
    cout << "Sparse table index : \n";
    display_sparse_table(sparse_table_index);

    cout << "Enter node 1 for finding LCA \t";
    int node1;
    cin >> node1;
    cout << "Enter node 2 for finding LCA \t";
    int node2;
    cin >> node2;

    int ans = lca(node1, node2, node_hash, reverse_lookup, sparse_table, sparse_table_index);
    cout << " LCA of " << node1 << " and " << node2 << " is " << ans << endl;

    return 0;
}