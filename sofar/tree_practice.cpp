#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> visited;

vector<int> find_center()
{
    int len = graph.size();
    cout << len << endl;
    vector<int> degree(len, 0);
    vector<int> leaves;
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
        cout << count << endl;
    }
    return leaves;
}

void root_the_tree(int node)
{
    if(visited[node] != 0)
    {
        return;
    }
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if(visited[graph[node][i]] == 0)
        {
            tree[node].push_back(graph[node][i]);
            root_the_tree(graph[node][i]);
        }
    }
    
}

void display_graph(vector<vector<int>> graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


string encode(int node)
{
    if(tree[node].size() == 0)
    {
        return "()";
    }
    vector<string> s;
    for(int i = 0; i < tree[node].size(); i++)
    {
        s.push_back(encode(tree[node][i]));
    }
    sort(s.begin(), s.end());
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        temp += s[i];
    }
    return "(" + temp + ")";
}



int main()
{
    int n, no_of_neighbours, neighbours;
    cin >> n;
    graph.resize(n);
    tree.resize(n);
    visited.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_neighbours;
        for(int j = 0; j < no_of_neighbours; j++)
        {
            cin >> neighbours;
            graph[i].push_back(neighbours);
            //graph[neighbours].push_back(i);
        }
    }
    //display_graph(graph);
    vector<int> center_of_tree = find_center();
    cout << "hi";
    root_the_tree(center_of_tree[0]);
    cout << "Center of the tree " << center_of_tree[0] << endl;
    display_graph(tree);
    string s = encode(center_of_tree[0]);
    cout << s << endl;

    vector<string> temp  = {"()", "(())", "((()()()))"};
    sort(temp.begin(), temp.end());
    cout << endl << temp[0];
}