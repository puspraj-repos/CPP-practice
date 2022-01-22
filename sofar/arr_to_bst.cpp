#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;
};


tree *create_node(int data)
{
    tree *node = new tree;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct node
{
    int data;
    node* next;
};

node* create_list_node(int data)
{
    node* temp = new node;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

node *push(node *head, int data)
{
    node *temp = create_list_node(data);
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

node *pop(node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    return head;
}


tree *construct_tree(vector<int> arr, int l, int r)
{
    if(r < l)
    {
        return NULL;
    }
    if(l == r)
    {
        tree *temp = create_node(arr[l]);
        return temp;
    }
    int mid = (l+r)/2;
    tree *left_child = construct_tree(arr, l, mid - 1) ;
    tree *right_child = construct_tree(arr, mid + 1, r);
    tree *node = create_node(arr[mid]);
    node->left = left_child;
    node->right = right_child;
    return node;
}

void inorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        head = push(head, arr[i]);
    }

    tree *root = construct_tree(arr, 0, n-1);
    inorder(root);
}