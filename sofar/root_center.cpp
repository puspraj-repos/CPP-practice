#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> graph;
// vector<vector<int>> graph2;
// vector<int> visited, visited2;

struct tree
{
    int item;
    tree *parent;
    vector<tree*> childs;
};

vector<int> find_center(vector<vector<int>> graph)
{
    //cout <<"hi";
    vector<int> degree;
    vector<int> leaves;
    for(int i = 0; i < graph.size(); i++)
    {
        degree.push_back(graph[i].size());
        if(graph[i].size() <= 1)
        {
            leaves.push_back(i);
        }
    }
    int count = leaves.size();
    while(count < graph.size())
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
        count += new_leaves.size();
        leaves = new_leaves;
    }
    return leaves;
}

tree* create_node(int item)
{
    tree *temp = new tree;
    temp->parent = NULL;
    temp->item = item;
    return temp;
}

tree* root_the_tree(int item, vector<int> visited, vector<vector<int>> graph)
{
    queue<tree*> nodes;
    tree *root = create_node(item);
    nodes.push(root);
    while(nodes.empty() == false)
    {
        tree *temp = nodes.front();
        nodes.pop();
        if(visited[temp->item] == 0)
        {
            visited[temp->item] = 1;
            for(int i = 0; i < graph[temp->item].size(); i++)
            {
                if(visited[graph[temp->item][i]] == 0)
                {
                    tree *temp2 = create_node(graph[temp->item][i]);
                    temp2->parent = temp;
                    temp->childs.push_back(temp2);
                    nodes.push(temp2);
                }
            }
        }
    }
    return root;
}

void preorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->item << " ";
    for(int i = 0; i < root->childs.size(); i++)
    {
        preorder(root->childs[i]);
    }
}

string encode(tree* root)
{
    if(root == NULL)
    {
        return "";
    }
    string ans = "";
    vector<string> temp;
    for(int i = 0; i < root->childs.size(); i++)
    {
        temp.push_back(encode(root->childs[i]));
    }
    sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++)
    {
        ans+=temp[i];
    }
    
    return "(" + ans + ")";
}


int main()
{
    vector<vector<int>> graph, graph2;
    vector<int> visited, visited2;
    int n;
    cin >> n;
    visited.resize(n, 0);
    graph.resize(n);

    int v,m;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }

    //graph2
    cin >> n;
    visited2.resize(n, 0);
    graph2.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> v;
            graph2[i].push_back(v);
        }
    }
    vector<int> center = find_center(graph);
    cout << center[0] << endl;
    tree *root = root_the_tree(center[0], visited, graph);

    vector<int> center2 = find_center(graph2);

    string encoding = encode(root);
    cout << encoding << endl;
    preorder(root);
    cout << endl;
    for(int i = 0; i < center2.size(); i++)
    {
        vector<int> visited3(n, 0);   
        tree* temp = root_the_tree(center2[i], visited3, graph2);
        string encoding2 = encode(temp);
        cout << encoding2 << endl;
        if(encoding2 == encoding)
        {
            cout <<"Yes";
            return 0;
        }
    }
    cout << "No";
}