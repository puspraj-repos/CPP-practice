#include<bits/stdc++.h>
using namespace std;

enum state {UP, DOWN, NONE};

class A
{
public:
    state lift_state;
    A(): lift_state(NONE){}
    void get_state()
    {
        cout <<lift_state;
    }
};

int main()
{
    A obj;
    obj.get_state();
}