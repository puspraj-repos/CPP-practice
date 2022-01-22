#include<bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
int solution(vector<int> &A, int K, int L) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    if(K+L > len)
    {
        return -1;
    }
    vector<int> prefix(len+1, 0);
    int sum = 0;
    for(int i = 1; i <=len; i++)
    {
        prefix[i] = sum + A[i - 1];
        sum = prefix[i];
    }
    int left, right;
    int temp_l, temp_k;
    int sum_intervals = -1;
    for(int i = K; i < len+1; i++)
    {
        left = i - K;
        right = len - i;
        int left_sum = -1, right_sum = -1;
        int current_sum = prefix[i] - prefix[i - K];
        //cout << current_sum << endl;
        //cout << "left sum : " ;
        for(int j = L; j <= left; j++)
        {
            //cout << prefix[j] - prefix[j - L]<< " ";
            if(left_sum < (prefix[j] - prefix[j - L]))
            {
                left_sum = prefix[j] - prefix[j - L];
            }
            
        }
        //cout << "right sum ";
        for(int k = i + L; k <= len; k++)
        {
            //cout << prefix[k] - prefix[k - L]<< " ";
            if(right_sum < (prefix[k] - prefix[k - L]))
            {
                right_sum = prefix[k] - prefix[k - L];
            }
        }
        //cout << "tem sum " ;
        if(left_sum != -1 or right_sum != -1)
        {
            int temp_sum = current_sum + max(left_sum, right_sum);
            //cout << temp_sum << endl;
            if(sum_intervals < temp_sum)
            {
                sum_intervals = temp_sum;
            }
        }
    }
    return sum_intervals;

}

vector<string> solution2(int N, int K) {
    if (N == 0 || K == 0) {
        return {""};
    }
    cout << "hi";
    vector<string> result;
    for (string& p : solution2(N - 1, K)) {
        for (char l : string("abc")) {
            if (p.empty() || (p.back() != l)) {
                p.push_back(l);
                result.push_back(p);
                p.pop_back();
            }
        }
    }
    int pref_size = min((int) result.size(), K);
    return vector<string>(result.begin(), result.begin() + pref_size);
}


int main()
{
    vector<int> a = {6,1,1,2};
    // int ans = solution(a,2,1);
    // cout << ans;
    vector<string> ans = solution2(3,0);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<< endl;
    }
}