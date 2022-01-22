#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int val;
    vector<tree *> childs;
};

tree *create_node(int index)
{
    tree *node = new tree;
    node->val = index;
    return node;
}

void dfs(tree *root, int &index, string s, int len)
{
    if (index == len)
        return;
    while (index < len)
    {
        if (s[index] == '(')
        {
            index++;
            tree *temp_node = create_node(index);
            root->childs.push_back(temp_node);
            dfs(temp_node, index, s, len);
        }
        else
        {
            index++;
            break;
        }
    }
}

int return_sum(tree *root)
{
    int ans = 1;
    int sum = 0;
    for (int i = 0; i < root->childs.size(); i++)
    {
        sum += return_sum(root->childs[i]);
    }
    return sum ? sum * 2 : ans;
}

int main()
{
    string s;
    cin >> s;
    tree *main_root = new tree;
    int sum = 0, index = 0;
    while (index < s.size())
        dfs(main_root, index, s, s.size());
    for(int i = 0; i < main_root->childs.size(); i++)
    {
        sum += return_sum(main_root->childs[i]);
        //cout << sum << endl;
    }

    cout << sum << endl;
    // cout << main_root->childs[0]->val << endl;
    // if (main_root->childs.size() > 1)
    // {
    //     cout << main_root->childs[1]->val << endl;
    // }
}