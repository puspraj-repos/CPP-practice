#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int flag=0;
        cin>>s;
        int arr[26]={0};
        int l=s.size();
        for(int i=0;i<l;i++)
        {
            arr[s[i]-97]++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]==1)
            {
                flag++;
            }
            else if(arr[i]!=0 && arr[i]%2==0)
            {
                count++;
            }
            
        }
        int ans=1;
        if(count<flag)
        {
            cout<<"NO"<<endl;
        }
        else 
        {
            cout<<"YES"<<endl;
        }
    }
}