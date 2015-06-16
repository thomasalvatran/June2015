#ifndef INTSTACK_H
#define INTSTACK_H
#include <iostream>
using namespace std;

template<class T>
class Stack {
    T *data;			//private no need to define private
    int length;
    int ptr;
    public:
    Stack(int);
    void push(T);
    T pop();
    T top() const;
    int size() const;
    ~Stack();
};

template<class T>
Stack<T>::Stack(int stk_size) {
    data = new T[length = stk_size];
    ptr = 0;
    cout << "constructor" << endl;
}

template<class T>
void Stack<T>::push(T x) {
    if (ptr < length)
        data[ptr++] = x;
    else
        throw "overflow";
}

template<class T>
T Stack<T>::pop() {
    if (ptr > 0)
        return data[--ptr];
    else
        throw "underflow";
}

template<class T>
T Stack<T>::top() const {
    if (ptr > 0)
        return data[ptr-1];
    else
        throw "underflow";
}

template<class T>
int Stack<T>::size() const {
    return ptr;
}

template<class T>
Stack<T>::~Stack() {
    delete [] data;
    cout << "destructor" << endl;
}



#endif // INTSTACK_H

