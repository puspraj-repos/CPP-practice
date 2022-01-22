#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> visited;

void update(int index, int val, vector<int> &arr)
{
    int len = arr.size();
    while(index < len)
    {
        arr[index] += val;
        index = index + (index & -index);
    }
}

int query(int left, int right, const vector<int> &arr)
{
    int sum = 0;
    while(right > 0)
    {
        sum += arr[right];
        right -= (right & -right);
    }
    left--;
    while(left > 0)
    {
        sum-= arr[left];
        left-= (left & -left);
    }
    return sum;
}


void preorder_postorder(int id, int &number, vector<int> &preorder, vector<int> &postorder, vector<int> &arr)
{
    visited[id] = 1;
    update(number, id, arr);
    preorder[id] = number;
    number++;
    for(int i = 0; i < tree[id].size(); i++)
    {
        if(visited[tree[id][i]] == 0)
        {
            preorder_postorder(tree[id][i], number, preorder, postorder, arr);
        }
    }
    postorder[id] = number++;
}

int main()
{
    int n, no_of_adjacent_nodes, adjacent;
    cin >> n;
    tree.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> no_of_adjacent_nodes;
        for(int j = 0; j < no_of_adjacent_nodes; j++)
        {
            cin >> adjacent;
            tree[i].push_back(adjacent);
            tree[adjacent].push_back(i);
        }
    }
    visited.resize(n, 0);
    vector<int> preorder(n);
    vector<int> postorder(n);
    vector<int> arr(2*n + 1, 0);
    int number = 1;
    preorder_postorder(0, number, preorder,postorder,arr);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << query(preorder[x], postorder[x], arr);
    }
    
}