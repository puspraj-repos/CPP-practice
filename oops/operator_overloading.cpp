#include<iostream>
using namespace std;


class fruits
{
public:
	int a, b;
    int arr[100];
public:
	fruits()
	{
		a = 0;
		b = 0;
        for(int i = 0; i < 100; i++)
        {
            arr[i] = 100;
        }
	}
	void add(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void display()
	{	
		cout << a << " " << b << endl;
	}
	fruits operator +(fruits const &obj)
	{
		fruits sum;
		sum.a = a + obj.a;
		sum.b = b + obj.b;
		return sum;
	}

    fruits operator ++(int i)
    {
        a+=1;
        b+=1;
        for(int i = 0; i < 100; i++)
        {
            arr[i]+=1;
        }
        return *this;
    }

    int operator [](int a)
    {
        return arr[a];
    }

    

    // ostream& operator <<(ostream &out)
    // {
    //     out << this->a << "," << this->b;
    //     return out;
    // }


    //friend because if we do not give friend, then the operator where we will try to use this object won't find this function(overloaded) because this is inside class. this is to 
    //note that we are using object after the operator so it becomes impossible to identify where the function is present, however in case of friend function it becomes possible.
    friend ostream& operator <<(ostream &out, fruits obj);
    friend istream& operator >>(istream &in, fruits &obj);
};

ostream& operator <<(ostream &out, fruits obj)
{
    out << obj.a << "," << obj.b;
    return out;
}

istream& operator >>(istream &in, fruits &obj)
{
    in >> obj.a >> obj.b;
    return in;
}



int main()
{
	fruits obj1;
    cin >> obj1;
    cout << obj1;
	return 0;
}
