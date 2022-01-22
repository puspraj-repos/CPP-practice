#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int minimum = 5;
        //cout << s;
        for(int i = 0; i < n; i++)
        {
            if(i + 1 < n)
            {
                if(s[i] == 'a' && s[i + 1] == 'a')
                {
                    minimum = 2;
                    break;
                }
            }
            if(i + 2 < n)
            {
                if(s[i] == 'a' && (s[i + 1] == 'b' || s[i + 1] == 'c') && s[i + 2] == 'a')
                {
                    if(minimum > 3)
                    {
                        minimum = 3;
                    }
                }
            }
            if(i + 3 < n)
            {
                if((s[i] == 'a' && s[i + 3] == 'a') && ((s[i + 1] == 'b' && s[i + 2] == 'c') || (s[i + 1] == 'c' && s[i + 2] == 'b')))
                {
                    if(minimum > 4)
                    {
                        minimum = 4;
                    }
                }
            }
        }
        if(minimum == 5)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << minimum << endl;
        }
    }
}