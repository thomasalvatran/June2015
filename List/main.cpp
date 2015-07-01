#include <QCoreApplication>
#include <iostream>
#include <list>
using namespace std;

class Cat {
    string name;
public:
    Cat(string name): name(name){}
    string getName() { return name; }
};

int main()
{

    list<Cat> lst;
    lst.push_back(Cat("Tom"));
    lst.push_back(Cat("TomTom"));
    lst.push_back(Cat("TomTomTom"));
    list<Cat>::iterator pcat = lst.begin();
    while(pcat != lst.end()){
        cout << pcat->getName() << endl;
        pcat++;
    }
    cout << "test" << endl;
    list<int> l;
    int i=0;
    for(i = 0; i< 10; i++)
        l.push_back(i);
    cout << "Size " << l.size() << endl;
    list<int>::iterator lp = l.begin();
    while(lp != l.end()){
        cout << *lp << endl;
        lp++;
    }

}
