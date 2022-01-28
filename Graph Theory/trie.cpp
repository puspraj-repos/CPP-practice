#include<bits/stdc++.h>
using namespace std;

struct trie
{
    vector<trie*> chars;
    bool is_end;

    trie()
    {
        is_end = false;
        chars.resize(26, nullptr);
    }
};

trie* create_node()
{
    trie* node = new trie;
    return node;
}

void insert(string &s, trie* root)
{
    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        int index = s[i] - 'a';
        if(root->chars[index] != nullptr)
        {
            root = root->chars[index];
        }
        else
        {
            root->chars[index] = create_node();
            root = root->chars[index];
        }
    }
    root->is_end = 1;
}

bool search(string &s, int start, trie* root)
{
    int len = s.size();
    for(int i = start; i < len; i++)
    {
        if(s[i] == '.')
        {
            for(int j = 0; j < 26; j++)
            {
                if(root->chars[j] != nullptr)
                {
                    //abc.
                    bool ans = root->chars[j]->is_end;
                    if(i + 1 < len)
                    {
                        ans = search(s, i + 1, root->chars[j]);
                    }
                    if(ans)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        }
        int index = s[i] - 'a';
        if(root->chars[index] == nullptr)
        {
            return 0;
        }
        else
        {
            root = root->chars[index];
        }
    }
    if(root->is_end)
    {
        return 1;
    }
    return 0;
}

int main()
{
    trie *root = new trie;
    int n;
    cin >> n;
    int type;
    string s = "puspraj";
    insert(s, root);
    for(int i = 0; i < n; i++)
    {
        cin >> type;
        cin >> s;
        if(type == 1)
        {
            insert(s, root);
        }
        else
        {
            cout << search(s, 0, root);
        }
    }
}