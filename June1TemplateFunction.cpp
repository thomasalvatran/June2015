#include <iostream>           //Aug 22, 2007 cplusplus1.doc p.105 template function
using namespace std;

//This is template function (generic function == template function) 
template <class T>  //place holder
T GetMax (T a, T b) {
	//  T result;
	//  result = (a>b) ? a : b;
	//  return (result);
	return ((a>b) ? a : b);
}

template <class X, class T>
void swapargs( X &a, T &b){
	X temp;

	cout << "swapargs(X a, T b) " << endl;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
void swapargs( T &a, T &b){
	T temp;

	cout << "swapargs(T a, T b) " << endl;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
void f(T s)
{
	cout << "f(T s) " << s << endl;
}

template<class T> //general
void f1(T s)
{
	cout << "f1(T s) " << s << endl;
}

template<class T>  //special
void f1(float s){ cout << "f1(int s) "<< s << endl; }

//always need a pair general and special
//has in order
template<int T> 
void f() { cout << "general template" << endl; }

template<>
void f<0>() { cout << "special template" << endl; }

int main()
{
	int i = 5, j = 6;
	long l = 10, m = 5;
	cout << GetMax<int>(5, 6) << endl;
	cout << GetMax<long>(10.1, 5.4) << endl;
	cout << GetMax(10.1, 5.4) << endl;
	f<float>(11.11);

	f1<float>(12.11);
	f1<int>(2.2);

	f<0>();
	f<1>();

	f<int>(1);

	int i1 = 10, j1 = 20;
	double x1 = 10.1, y1 = 23.3;
	char a1 = 'x', b1 = 'z';  

	cout << "Original i, j: " << i1 << ' ' << j1 << '\n';
	cout << "Original x, y: " << x1 << ' ' << y1 << '\n';
	cout << "Original a, b: " << a1 << ' ' << b1 << '\n';
	swapargs<int, int>(i1, j1); // swap integers
	swapargs(x1, y1); // swap floats
	swapargs(a1, b1); // swap chars
	cout << "Swapped i, j: " << i1 << ' ' << j1 << '\n';
	cout << "Swapped x, y: " << x1 << ' ' << y1 << '\n';
	cout << "Swapped a, b: " << a1 << ' ' << b1 << '\n';
	return 0;
}
//Compiling  /home/tovantran/Ctest/template.cpp
//template.cpp
//template
//6
//10
//10.1
//f(T s) 11.11
//f1(int s) 12.11
//f1(int s) 2.2
//special template
//general template
//f(T s) 1
//Original i, j: 10 20
//Original x, y: 10.1 23.3
//Original a, b: x z
//swapargs(X a, T b) 
//swapargs(T a, T b) 
//swapargs(T a, T b) 
//Swapped i, j: 20 10
//Swapped x, y: 23.3 10.1
//Swapped a, b: z x

//Done.


