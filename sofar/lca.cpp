#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> tour, node_to_num, num_to_node, height_node;
unordered_map<int, int> um;


int count_num = 0;

struct tree
{
    int id;
    tree* parent;
    vector<tree*> childs;
};

tree* create_node(int id)
{
    tree *temp = new tree;
    temp->id = id;
    temp->parent = NULL;
    return temp;
}

tree* root_tree(int id)
{
    tree *root = create_node(id);
    queue<tree*> nodes;
    nodes.push(root);
    while(nodes.empty() == false)
    {
        //cout << "hi";
        tree* temp = nodes.front();
        nodes.pop();
        if(visited[temp->id] == 0)
        {
            visited[temp->id] = 1;
            //tree *node = create_node(temp->id);
            for(int i = 0; i < graph[temp->id].size(); i++)
            {
                if(visited[graph[temp->id][i]] == 0)
                {
                    tree* new_node = create_node(graph[temp->id][i]);
                    nodes.push(new_node);
                    new_node->parent = temp;
                    temp->childs.push_back(new_node);
                    // cout << "hi";
                }
            }
        }
    }
    return root;
}

void preorder(tree* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->id << " " ;
    for(int i = 0 ; i < root->childs.size(); i++)
    {
        preorder(root->childs[i]);
    }
}

void euler_tour(tree *root)
{
    num_to_node.push_back(root->id);
    node_to_num[root->id] = count_num;
    tour.push_back(height_node[root->id]);
    count_num++;
    int flag = 0;
    for(int i = 0; i < root->childs.size(); i++)
    {
        euler_tour(root->childs[i]);
        num_to_node.push_back(root->id);
        node_to_num[root->id] = count_num;
        tour.push_back(height_node[root->id]);
        count_num++;
        
    }
}

int height(tree *root)
{
    int h = 0;
    for(int i = 0 ; i < root->childs.size(); i++)
    {
        int temp_h = height(root->childs[i]);
        if(h < temp_h + 1)
        {
            h = temp_h + 1;
        }
    }
    height_node[root->id] = h;
    return h;
}

void print_details()
{
    for(int i = 0; i < graph.size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < graph.size(); i++)
    {
        cout << height_node[i] << " ";
    }
    cout << endl << endl << "Node Identification" << endl;
    for(int i = 0; i < node_to_num.size(); i++)
    {
        cout << node_to_num[i] << " ";
    }
    cout << endl << endl << "Preorder Number" << endl;
    for(int i = 0; i < num_to_node.size(); i++)
    {
        cout << num_to_node[i] << " ";
    }
    cout << endl << endl << " height" << endl;
    for(int i = 0 ; i < tour.size(); i++)
    {
        cout << tour[i] << " ";
    }
}

void create_table(vector<vector<int>> &table, vector<vector<int>> &index)
{
    int col = tour.size();
    int row = log2(col);
    table.resize(row);
    index.resize(row);
    for(int i = 0; i < col; i++)
    {
        table[0].push_back(tour[i]);
        index[0].push_back(i);

    }
    for(int i = 1; i < row; i++) 
    {
        for(int j = 0; j < col; j++)
        {
            int offset = (1<<(i-1)) + j;
            if(offset < col)
            {
                if(table[i-1][j] > table[i-1][offset])
                {
                    table[i].push_back(table[i-1][j]);
                    index[i].push_back(index[i-1][j]);
                }
                else
                {
                    table[i].push_back(table[i-1][offset]);
                    index[i].push_back(index[i-1][offset]);
                }
            }
        }
    }
}

int query(int l, int r, vector<vector<int>> &sparse_table, vector<vector<int>> index)
{
    int len = r - l + 1;
    int left = l;
    int row = log2(len);
    int right = r - (1<<row) + 1;
    int ans;
    if(sparse_table[row][left] > sparse_table[row][right])
    {
        ans = index[row][left];
    }
    else
    {
        ans = index[row][right];
    }
    return num_to_node[ans];
}

int main()
{
    int n, edges, v;
    cin >> n;
    graph.resize(n);
    node_to_num.resize(n);
    height_node.resize(n);
    visited.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> v;
        for(int j = 0; j < v; j++)
        {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }
    tree *root = root_tree(2);
    preorder(root);
    cout << endl;
    height(root);
    euler_tour(root);
    print_details();


    vector<vector<int>> sparse_table, index;
    create_table(sparse_table, index);
    int q;
    cin >> q;
    int a, b;
    for(int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a = node_to_num[a];
        b = node_to_num[b];
        cout << query(min(a, b),max(a, b),sparse_table, index) << endl;
    }
}