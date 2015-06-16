#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include "bqueue.h"
using namespace std;

int main(int argc, char *argv[]) {

//  IntQueue Q; //in stack
  IntQueue *list = new IntQueue; //heap
  cout << list->Front() << " " << list->Rear() << endl;
  //      list->Enqueue(22);
  //      list->Enqueue(23);
  for (int i = 0; i < 10; i++) {
    list->Enqueue(i + 10);
  }
  list->Print();
  cout << "front =" << list->Front() << ", rear = " << list->Rear() << endl;
  //  list->Dequeue();
  list->Dequeue();
  list->Dequeue();
  list->Enqueue(669);
  list->Enqueue(677);
  list->Enqueue(688);
  list->Print();

  cout << "front =" << list->Front() << ", rear = " << list->Rear() << endl;
  while (list->isEmpty() == 0) {
    list->Dequeue();
  }

  cout << "queue front is " << list->Front() << endl;
  printf("Queue is %s\n", list->isEmpty() ? "empty " : "not empty ");
  list->Enqueue(222);
  list->Enqueue(223);
  cout << "queue front is " << list->Front() << endl;
  printf("Queue is %s\n", list->isEmpty() ? "empty " : "not empty ");
  list->Print();
}
