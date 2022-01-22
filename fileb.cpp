

#include <iostream> 
using namespace std; 

class Increment { 
private: 
	int val; 
public: 

	Increment() 
	{ 
		val=0;
	} 

	Increment operator++() 
	{ 
		Increment temp; 
		temp.val=temp.val+5; 
		return temp; 
	} 

  Increment operator++(int) 
    { 
        Increment temp; 
        temp.val = temp.val+5; 
        return temp; 
    }

	void show() 
	{ 
		cout << "val = " << val << endl; 
	} 
}; 

int main() 
{ 
	Increment value1,value2; 
	Increment valuea = ++value1; 
    Increment valueb= value2++;
	value1.show();
    valuea.show();
    value2.show();
    valueb.show();
	
}


// // // C++ program to demonstrate 
// // // prefix increment operator overloading 

// // #include <bits/stdc++.h> 
// // using namespace std; 

// // class Integer { 
// // private: 
// // 	int i; 

// // public:  
// // 	Integer(int i ) 
// // 	{ 
// // 		i=0; 
// // 	} 

// // 	// Overloading the prefix operator 
// // 	Integer operator++() 
// // 	{ 
// // 		Integer temp; 
// // 		temp.i = ++i; 
// // 		return temp; 
// // 	} 
// //     // Integer operator++(int) 
// //     // { 
// //     //     Integer temp; 
// //     //     temp.i = i++; 
// //     //     return temp; 
// //     // }

// // 	// Function to display the value of i 
// // 	void display() 
// // 	{ 
// // 		cout << "i = " << i << endl; 
// // 	} 
// // }; 

// // // Driver function 
// // int main() 
// // { 
// // 	Integer i1; 

// // 	i1.display(); 

// // 	// Using the pre-increment operator 
// // 	Integer i2 = ++i1; 
// // 	i2.display(); 
// // } 


// // C++ program to demonstrate 
// // postfix increment operator overloading 

// #include <bits/stdc++.h> 
// using namespace std; 

// class Integer { 
// private: 
// 	int i; 

// public: 
// 	// Parameterised constructor 
// 	Integer(int i = 0) 
// 	{ 
// 		this->i = i; 
// 	} 

// 	// Overloading the postfix operator 
// 	Integer operator++(int) 
// 	{ 
// 		Integer temp; 
// 		temp.i = i++; 
// 		return temp; 
// 	} 

// 	// Function to display the value of i 
// 	void display() 
// 	{ 
// 		cout << "i = " << i << endl; 
// 	} 
// }; 

// // Driver function 
// int main() 
// { 
// 	Integer i1(3); 

// 	cout << "Before increment: "; 
// 	i1.display(); 

// 	// Using the post-increment operator 
// 	Integer i2 = i1++; 

// 	cout << "After post increment: "; 
// 	i2.display(); 
// } 
