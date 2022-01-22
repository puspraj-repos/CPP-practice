#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int row = (log(n)/log(2));
    vector<vector<int>> table(row + 1);
    for(int i = 0; i <= row; i++)
    {
        table[i].resize(n, 0);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> table[0][i];
    }
    for(int i = 1; i <= row; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int offset = j + (1<<(i - 1));
            if(offset < n)
            {
                table[i][j] = min(table[i - 1][j], table[i - 1][offset]);
            }
        }
    }
    // for(int i = 0; i < row; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int q, l, r;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> l >> r;
        if(l == r)
        {
            cout << table[0][l] << endl;
            continue;
        }
        int len = r - l + 1;

        int left = l;
        int downward = log2(len);
        int right = r - (1<<downward) + 1;
        int ans = min(table[downward][l], table[downward][right]);
        // int downward = log2(len);
        // cout << downward;
        // int left = l;
        // int right = r - (1<<(downward)) + 1;
        // int ans = min(table[downward][left], table[downward][right]);
        cout << ans;

        

    }


}