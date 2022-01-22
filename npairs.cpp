#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s_size;
        cin>>s_size;
        char s[s_size];
        cin>>s;
        int count=0;
        //int s_size=s.length();
        for(int i=0;i<s_size;i++)
        {
            int l=i-9;
            int r=i+9;
            // while(j>=0)P
            // {
            //     if((i-j)==abs(s[i]-s[l]))
            // }
            // for(int j=i;j>=0 && (j>=l);j--)
            // {
            //     if((i-j)==abs(s[i]-s[j]))
            //     {
            //         count++;
            //     }
            // }
            for(int j=i+1;j<s_size && (j<=r);j++)
            {
                if((j-i)==abs(s[j]-s[i]))
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}