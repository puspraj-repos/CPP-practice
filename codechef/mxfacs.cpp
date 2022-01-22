#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> parent_table, sum_table, adjacency_list;
vector<int> values, level;
int depth, n;

void find_level_and_sum(int node, int current_level, int current_sum)
{
    sum_table[0][node] = current_sum + values[node];
    level[node] = current_level;
    int len = adjacency_list[node].size();
    for(int i = 0; i < len; i++)
    {
        find_level_and_sum(adjacency_list[node][i], current_level + 1, sum_table[0][node]);
    }
}

void build_complete_parent_table()
{
    for(int i = 1; i < depth; i++)
    {
        for(int j = 2; j < n; j++)
        {
            if(parent_table[i-1][parent_table[i-1][j]] != -1)
            {
                parent_table[i][j] = parent_table[i-1][parent_table[i-1][j]];
            }
        }
    }
}

void update_table(int node, int parent)
{
    parent_table[0][node] = parent;
    for(int i = 1; i < depth; i++)
    {
        if(parent_table[i-1][parent_table[i-1][node]] != -1)
        {
            parent_table[i][node] = parent_table[i-1][parent[i-1][node]];
        }
        else
        {
            break;
        }
    }
    level[node] = level[parent] + 1;
    sum_table[0][node] = sum_table[0][parent] + values[node];
}


void display_2d_vector(vector<vector<int>> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void display_vector(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

using namespace std;
int main()
{
    cin >> n;
    depth = log2(n) + 1;
    int x;
    parent_table.resize(depth);
    sum_table.resize(depth);
    values.resize(n+1);
    level.resize(n + 1);
    adjacency_list.resize(n + 1);
    for(int i = 0; i < depth; i++)
    {
        parent_table[i].resize(n + 1, -1);
        sum_table[i].resize(n + 1, n - 1);
    }
    for(int i = 2; i <= n; i++)
    {
        cin >> x;
        parent_table[0][i] = x;
        adjacency_list[x].push_back(i);
    }
    parent_table[0][1] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        values[i] = x;
    }
    find_level_and_sum(1, 0, 0);
    cout << "displaying parent Table" << endl;
    display_2d_vector(parent_table);
    cout << "displaying sum table" << endl;
    display_2d_vector(sum_table);
    cout << "displaying level" << endl;
    display_vector(level);
}