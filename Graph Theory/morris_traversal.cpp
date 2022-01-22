#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;
};

tree* create_node(int data)
{
    tree *node = new tree;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

tree* insert_in_binary_tree(tree * root, int data)
{
    tree *node = create_node(data);
    if(root == nullptr)
    {
        root = node;
        return root;
    }
    queue<tree*> nodes;
    nodes.push(root);
    while(nodes.empty() == false)
    {
        tree* temp_node = nodes.front();
        nodes.pop();
        if(temp_node->left == nullptr)
        {
            temp_node->left = node;
            break;
        }
        else if(temp_node->right == nullptr)
        {
            temp_node->right = node;
            break;
        }
        else
        {
            nodes.push(temp_node->left);
            nodes.push(temp_node->right);
        }
    }
    return root;
}

void inorder(tree* root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void morris_traversal(tree *root)
{
    tree* node = root;
    while(node != NULL)
    {
        if(node->left != NULL)
        {
            tree *temp = node->left;
            while(temp->right != NULL and temp->right != node)
            {
                temp = temp->right;
            }
            if(temp->right == node)
            {
                temp->right = NULL;
                cout << node->data << " ";
                node = node->right;
            }
            else
            {
                temp->right = node;
                node = node->left;
            } 
        }
        else
        {
            cout << node->data << " ";
            node = node->right;
        }
    }
}

// we could also use separate function which precomputes height of all nodes and then use that height to calculate diameter
pair<int, int> tree_diameter(tree *root)
{
    if(root == NULL)
    {
        return {0,-1};
    }
    else
    {
        if(root->left != NULL and root->right != NULL)
        {
            // return 2 + tree_diameter(root->left) + tree_diameter(root->right);
            auto l = tree_diameter(root->left);
            auto r = tree_diameter(root->right);
            int height_left = l.second;
            int height_right = r.second;
            return {max(max(2 + height_left + height_right, l.first), r.first), max(height_left, height_right) + 1};
        }
        else if(root->left != NULL)
        {
            auto l = tree_diameter(root->left);
            return {max(1 + l.second, l.first), l.second + 1};
        }
        else if(root->right != NULL)
        {
            auto r = tree_diameter(root->right);
            return {max(1 + r.second, r.first), r.second + 1};
        }
    }
    return {0,0};
}

int main()
{
    int n;
    cin >> n;
    int x;
    tree *root = nullptr;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        root = insert_in_binary_tree(root, x);
    }
    inorder(root);
    cout << endl;
    morris_traversal(root);

    auto ans = tree_diameter(root);
    cout << endl;
    cout << ans.first << " " << ans.second << endl;
}