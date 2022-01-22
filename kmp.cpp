#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2;
    cin >> s;
    cin >> s2;
    int len = s.size();
    vector<int> lps(len, 0);
    for(int i = 1; i < len; i++)
    {
        int count = 1;
        int j = 0;
        while(i < len and s[i] == s[j])
        {
            lps[i] = count;
            count++;
            i++;
            j++;
        }
    }

    for(int i = 0; i < len; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    int len2 = s2.size();
    int j = -1;
    for(int i = 0; i < len2; i++)
    {
        if(j + 1 < len)
        {
            if(s[j + 1] == s2[i])
            {
                //cout << j << " ";
                j++;
                continue;
            }
            else
            {
                j = lps[j] - 1;
                if(j != -1)
                {
                    i--;
                }
                // i--;
                //i-=2;   
            }
        }
        else
        {
            cout << "found at " << i - len << " index";
            break;
        }
    }
}

//aabaac
//010120
//aaaabaaaabaac

// a    b   a   b   d
// 0    0   1   2   0

// 0    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
// ababcabcabababdm
