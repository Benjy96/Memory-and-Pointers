#include "../../../../Libraries/std_lib_facilities.h"

/*
	Purpose:
		Elucidation of memory, pointers, and references.

	Notes:
	OPERATORS
		- & is the reference operator. Gets the address of the object.

		e.g.: 
			int b = 0;
			void(int& b)								//Pass by reference
			{
				b = 10;									//normally, we pass by value (create a copy)
			}											//if we wanted to modify b outside the
														//scope of the function when passing
														//by value, we would have to return b

			cout << "b is now: " << b;					//b is now: 10

		- * is the pointer operator. Accesses the ADDRESS of the object. Use reference to assign it.
			examples demonstrating this are beneath in main method

		e.g.: 
			int* p = &b;								//p now holds memory address of b

	MEMORY
		- Allocating memory using the "new" keyword uses memory on the "heap"/store.

		Memory layout:
			|	Code		|							//What it says on the tin
			|	Static data	|							//For global variables
			|	Free store	|							//Available through: "new" (allocation)
			|	Stack		|							//Function calls, arguments & local variables

		e.g: double* p = new double[4];					//"New" allocates 4 doubles on free store  
														//and returns a pointer to the first double.
														//Known as "Free-store allocation"

		- p[0] means the same as *p
		- Memory leak example:
			{
				double* p = new double[5];				//Never de-allocated
				return x;
			}
		- Delete frees individual object allocated by new, Delete[] an array

*/
//----- Vectors

class vector1 {											//Leaks memory, no delete/destructor
private:
	int sz;												//Size of vector
	double* elem;										//A pointer to elements

public:				
	//Constructor
	vector1(int s) : sz{ s }, elem{ new double[s] }		//Initialize size and elem
	{
		for (int i = 0; i < s; ++i) elem[i] = 0;		//Initialize elements
	}

	//Methods
	int size() const { return sz; }
};

class vector2 {
private:
	int sz;
	double* elem;
	
public:
	//Constructor
	vector2(int s) : sz{ s }, elem{ new double[s] } 
	{
		for (int i = 0; i < s; ++i) elem[i] = 0;		//Subscript is same as content-of operator *
	}

	//Destructor
	~vector2() { delete[] elem; }						//Delete[] means delete multiple (array)

	//...methods
};

//-----

void sizes(char ch, int i, int* p, bool b, double d, string s) 
{
	cout << "the size of char is: " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is: " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is: " << sizeof(int*) << ' ' << sizeof(p) << '\n';
	cout << "the size of bool is: " << sizeof(bool) << ' ' << sizeof(b) << '\n';
	cout << "the size of double is: " << sizeof(double) << ' ' << sizeof(d) << '\n';
	cout << "the size of string is: " << sizeof(string) << ' ' << sizeof(s) << '\n';
}

int main() 
{
	char a = 'a';
	int b = 10;
	int* p = &b;		//pointer to b's memory address, an int sized piece of memory
	bool boolean = true;
	double d = 10.56;
	string s = "Hello, world!";
	
	cout << "b's memory address: " << p << ", b's contents: " << *p;	//last: content-of operator (deref)
	cout << '\n';

	sizes(a, b, p, boolean, d, s);
	
	keep_window_open();
	return 0;
}