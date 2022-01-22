#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long a,s,b;
        cin >> a >> s;
        int flag = 1;
        stack<long long> ans;
        while(a != 0 || s != 0)
        {
            int index_a = a%10;
            a = a/10;
            if(s == 0)
            {
                flag = 0;
                break;
            }
            int index_s = s%10;
            s = s/10;
            if(index_s < index_a)
            {
                if(s%10 != 1)
                {
                    flag = 0;
                    break;
                }
                s = s/10;
                ans.push(10+index_s - index_a);
            }
            else
            {
                ans.push(index_s - index_a);
            }
        }
        if(flag == 1)
        {
            long long num =0;
            while(ans.empty() == false)
            {
                num = num*10 + ans.top();
                ans.pop();
            }
            cout << num << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}