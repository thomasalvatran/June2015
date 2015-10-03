#include <stdio.h>
#include <iostream>
using namespace std;

//general class template
template <class T>
class A{
public:
  void f() { cout << "general function template" << endl; }
};

//specical class template
template <>
class A<bool>
{
public:
  void f() { cout << "special function template" << endl; }
};

//Function template
template <int T> void f();
template <int T> void f() { cout << "general function template" << endl; };
template <> void f<0>() { cout << "f<0> function template" << endl; }


int main(){

	A<int> ai;
	ai.f();
	A<bool> ab;
	ab.f();
	
	f<1>(); //function template or template function
	f<0>();
	
}
