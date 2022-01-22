#include <bits/stdc++.h>
using namespace std;


template<class T>

class Test
{
    T a, b;

    public: 
    Test(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    Test()
    {
        //default constructor
    }

    public:
    void show()
    {
        cout<< a << b << endl;
    }

    void assign(T a, T b);
};

template< class T>
void Test<T>::assign(T a, T b)
{
    this->a = a;
    this->b = b;
}


int main()
{
    Test<int> obj;
    obj.assign(1,4);
    obj.show();
}