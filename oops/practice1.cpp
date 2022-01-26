#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    string name;
    // virtual void func() = 0;
    Animal() : name{""} {}
    Animal(string n) : name{n} {}
    void print()
    {
        cout << "Animal Class";
    }
};

class Organisms
{
public:
    void print()
    {
        cout << "This is Orgamisms";
    }
};

class Dog : virtual public Animal
{
public:
    Dog() : Animal("Dog") {}
    Dog(string n) : Animal(n) { cout << "Hi"; }
    void func() { cout << "Dog func " << name << endl; }
};

class Cat : virtual public Animal
{
public:
// void print()
// {
//     cout <<" this is Cat";
// }

};

class Test : public Cat, public Dog
{
    public:
};

string operator -(string s1, string s2)
{
    int len = s2.size();
    while(len!=0)
    {
        s1.pop_back();
        len--;
    }
    return s1;

}

 int main()
{
    // Dog d;
    // cout << d.name << endl;
    // d.func();

    // Animal *p = new Dog("Tiger");
    // p->func();
    // string s = "puspraj";
    // s = s - "aj";
    // cout << s;

    // cout << a;
}