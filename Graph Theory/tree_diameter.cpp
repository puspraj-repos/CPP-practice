#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> height;

vector<int> tree_center(vector<vector<int>> graph)
{
    vector<int> degrees(graph.size());
    vector<int> leaves;
    for(int i = 0; i < graph.size(); i++)
    {
        degrees[i] = graph[i].size();
        if(degrees[i] <= 1)
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
                degrees[graph[leaves[i]][j]] -= 1;
                if(degrees[graph[leaves[i]][j]] == 1)
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

class tree
{
    public:
    int id;
    vector<tree*> childs;
};

tree *create_node(int id)
{
    tree *node = new tree();
    node->id = id;
    return node;
}

void tree_dfs(tree *root, vector<vector<int>> graph)
{
    if(visited[root->id] != 0)
    {
        return;
    }
    visited[root->id] = 1;
    tree *node;
    for(int i = 0; i < graph[root->id].size(); i++)
    {
        if(visited[graph[root->id][i]] == 0)
        {
            node = create_node(graph[root->id][i]);
            root->childs.push_back(node);
            tree_dfs(node, graph);
        }
    }
}

int height_of_tree(tree *root)
{
    int max_height = 0;
    for(int i = 0; i < root->childs.size(); i++)
    {
        int temp = height_of_tree(root->childs[i]);
        if(max_height < temp)
        {
            max_height = temp;
        }
    }
    height[root->id] = max_height;
    return max_height + 1; 
}

tree *rootify(vector<vector<int>> graph, int id)
{
    tree *root = create_node(id);

    tree_dfs(root, graph);
    return root;

}

int find_diameter(tree *root)
{
    int max1=-1, max2=-1;
    for(int i = 0; i < root->childs.size(); i++)
    {
        int diameter= find_diameter(root->childs[i]);
        if(diameter > max1)
        {
            max2 = max1;
            max1 = diameter;
        }
        else if(max2 < diameter)
        {
            max2 = diameter;
        }
    }
    return max1 + max2 + 2;
}


void print_vector(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, no_of_edges, v;
    cin >> n;
    graph.resize(n);
    visited.resize(n, 0);
    height.resize(n,-1);
    // inserting into  graph
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
    vector<int> center = tree_center(graph);
    
    tree *root = rootify(graph, center[0]);

    height_of_tree(root);

    print_vector(height);

    int diameter = find_diameter(root);

    cout << "diameter " << diameter;

}