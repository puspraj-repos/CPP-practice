#include <bits/stdc++.h>
using namespace std;

/*

next greater eleement for each element in an array
[2,3,4,4,1]
[3,4,-1,-1,-1]
[3,4,-1,-1]

[2,3,4,5,1]

stack : 2 
[[2,0], [3,1], [4,2],[5,3],[1,4]]

5
[100,5,4,6,2,3,6]
[6]
5,4 
6
[6,6]

[5]
[5]
[6]
Naive approach : 

Traverse from next index till right, if not found maximum return -1, else return first max

(n-1) + (n-2), ()... 

*/
void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main() {
    // you can write to stdout for debugging purposes, e.g.
    //std::cout << "This is a debug message" << std::endl;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    display(arr);

    stack<int> processed_stack;
    processed_stack.push(0);
    int current;
    for(int i = 1; i < n; i++)
    {
        current = arr[i];
        while(processed_stack.size() > 0 and arr[processed_stack.top()] < current)
        {
            arr[processed_stack.top()] = current;
            processed_stack.pop();
        }
        processed_stack.push(i);
    }
    while(processed_stack.size() > 0)
    {
        arr[processed_stack.top()] = -1;
        processed_stack.pop();
    }

    display(arr);
    return 0;
}
