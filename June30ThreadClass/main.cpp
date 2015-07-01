#include <memory>
#include "thread.h"
#include <iostream>
using namespace std;

// shared variable
int s = 0;

class communicatingThread: public Thread {
public:
    communicatingThread(int ID) : myID(ID) {}
    virtual void* run();
private:
    int myID;
};

void* communicatingThread::run() {
    cout << "Thread " << myID << " is running!" << endl;
    // increment s by million times
    for (int i = 0; i < 1000000; i++) s+=1;
    return 0;
}

using namespace std;

int main() {

    auto_ptr<communicatingThread> thread1(new communicatingThread(1));
    auto_ptr<communicatingThread> thread2(new communicatingThread(2));
    thread1->start();
    thread2->start();
    thread1->join();
    thread2->join();

    cout << "s = " << s << endl;
    TestClass x;
    x.print();

    return 0;
}
