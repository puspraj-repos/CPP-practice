// template specialization only comes in picture, when you want two same function, class with different behaviour.
// make sure we have same type of return type and parameter when using template specialization


#include<bits/stdc++.h>
using namespace std;

template<class T>
class Test
{
    public:
    Test(T x)
    {
        cout<<"It is not a char";
    }
};
template<>
class Test<char>
{
    public:
    Test(char x)
    {
        cout<<"It is a char";
    }
};

template< class T>
T add(T a, T b)
{
    return a + b;
}
template<>
char add<char>(char a, char b)
{
    return a+b;
}


int main()
{
    Test<int> obj(1);
    Test<char> obj2('d');

}