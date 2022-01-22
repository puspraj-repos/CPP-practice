#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> weight(n);
        for(int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        sort(weight.begin(), weight.end());
        int count = 0;
        int prev = weight[0];
        int flag = 0;
        vector<pair<int, int>> weight_unique;
        for(int i = 0; i < n; i++)
        {
            if(prev == weight[i])
            {
                count++;
            }
            else
            {
                weight_unique.push_back({prev, count});
                count = 1;
                prev = weight[i];
            }
        }
        weight_unique.push_back({prev, count});
    }
}

//123903423423
//12393423423
//12390342345