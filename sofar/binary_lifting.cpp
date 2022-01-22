#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> visited;
vector<vector<int>> table;
vector<int> depth;

vector<int> find_center()
{
    int len = graph.size();
    vector<int> leaves;
    vector<int> degree(len, 0);
    for(int i = 0; i < len; i++)
    {
        degree[i] = graph[i].size();
        if(degree[i] <= 1)
        {
            leaves.push_back(i);
        }
    }
    int count = leaves.size();
    while(count < len)
    {
        vector<int> new_leaves;
        for(int i = 0; i < leaves.size(); i++)
        {
            for(int j = 0; j < graph[leaves[i]].size(); j++)
            {
                degree[graph[leaves[i]][j]]--;
                if(degree[graph[leaves[i]][j]] == 1)
                {
                    new_leaves.push_back(graph[leaves[i]][j]);
                }
            }
        }
        leaves = new_leaves;
        count += leaves.size();
    }
    return leaves;
}

void root_the_tree(int node)
{
    queue<int> nodes;
    nodes.push(node);
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

void dfs(int node, int d)
{
    depth[node] = d;
    for(int i = 0; i < tree[node].size(); i++)
    {
        table[0][tree[node][i]] = node;
        dfs(tree[node][i], d + 1);
    }
}

void build_table()
{
    int len = table[0].size();
    for(int i = 1; i < table.size(); i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(table[i-1][j] != -1)
            {
                table[i][j] = table[i-1][table[i-1][j]];
            }
            else
            {
                table[i][j] = -1;
            }
            
        }

    }
}

void display_vector_array(vector<vector<int>> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int binary_search(int l, int r)
{
    int n = table.size() - 1;
    int ans = l;
    while(n >= 0)
    {
        if(table[n][l] != table[n][r])
        {
            l = table[n][l];
            r = table[n][r];
        }
        n--;
    }
    ans = table[0][l];
    return ans;
}

int walk(int diff, int node)
{

    int count = 0;
    while(diff != 0)
    {
        if(diff&1)
        {
            node = table[count][node];
        }
        count++;
        diff = diff>>1;
    }
    return node;
}

int lca(int l, int r)
{
    int depth_l = depth[l];
    int depth_r = depth[r];
    int diff = abs(depth_r - depth_l);
    int same_level_node;
    int node_a, node_b;
    if(depth_l > depth_r)
    {
        node_a = r;
        same_level_node = walk(diff, l);
        node_b = same_level_node;
    }
    else
    {
        same_level_node = walk(diff, r);
        node_a = l;
        node_b = same_level_node;
    }
    if(node_a == node_b)
    {
        return node_a;
    }
    //cout << node_a << " " << node_b << endl;
    return binary_search(node_a, node_b);
}

int main()
{
    int n, v, x;
    cin >> n;
    graph.resize(n);
    visited.resize(n, 0);
    tree.resize(n);
    int table_row = ceil(log2(n));
    table.resize(table_row);
    depth.resize(n);
    for(int i = 0; i < table_row; i++)
    {
        table[i].resize(n, -1);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        for(int j = 0; j < v; j++)
        {
            cin >> x;
            graph[i].push_back(x);
        }
    }

    int center = find_center()[0];
    root_the_tree(center);
    dfs(center, 0);
    build_table();
    // cout << center << endl;
    // display_vector_array(tree);
    // cout << endl;
    // display_vector_array(table);
    // cout << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << lca(l,r) << endl;
    }
}