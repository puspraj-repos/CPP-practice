#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int id;
    tree *left, *right;
};

tree *create_node(int id)
{
    tree *node = new tree;
    node->left = NULL;
    node->right = NULL;
    node->id = id;
    return node;
}

int height(tree *root)
{
    if(root == NULL)
    {
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}


void inorder(tree *root)
{
    if(root == NULL)
    {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

void preorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->id << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->id << " ";
}

tree *left_rotate(tree *root)
{
    tree* temp_root = root;
    root = root->right;
    temp_root->right = root->left;
    root->left = temp_root;
    return root;
}
tree *right_rotate(tree *root)
{
    tree* temp_root = root;
    root = root->left;
    temp_root->left = root->right;
    root->right = temp_root;
    return root; 
}

tree *insert(tree *root, int id)
{
    tree *node;
    node = create_node(id);
    if(root == NULL)
    {
        root = node;
        return node;
    }
    stack<tree*> nodes; 
    tree *parent = root;
    tree *swim = root;
    bool flag = 0;
    while(swim != NULL)
    {
        parent = swim;
        nodes.push(parent);
        if(swim->id < id)
        {
            flag = 0;
            swim = swim->right;
        }
        else
        {
            flag = 1;
            swim = swim->left;
        }
    }
    if(flag == 0)
    {
        parent->right = node;
    }
    else
    {
        parent->left = node;
    }
    // int left_height = height(root->left);
    // int right_height = height(root->right);
    // if(left_height - right_height > 1)
    // {
    //     root = right_rotate(root);
    // }
    // else if(right_height - left_height > 1)
    // {
    //     root = left_rotate(root);
    // }
    tree *temp_node = root;
    while(nodes.empty() == false)
    {
        temp_node = nodes.top();
        nodes.pop();
        int left_height = height(temp_node->left);
        int right_height = height(temp_node->right);
        if(left_height - right_height > 1)
        {
            temp_node = right_rotate(temp_node);
            if(nodes.size() > 0)
            {
                if(nodes.top()->id > temp_node->id)
                {
                    nodes.top()->left = temp_node;
                }
                else
                {
                    nodes.top()->right = temp_node;
                }
            }
            break;
        }
        else if(right_height - left_height > 1)
        {
            temp_node = left_rotate(temp_node);
            if(nodes.size() > 0)
            {
                if(nodes.top()->id > temp_node->id)
                {
                    nodes.top()->left = temp_node;
                }
                else
                {
                    nodes.top()->right = temp_node;
                }
            }
            break;
        }
    }
    if(nodes.size() == 0)
    {
        root = temp_node;
    }
    return root;
}


int main()
{
    tree *root=NULL;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
        preorder(root);
        cout << endl;
    }

}