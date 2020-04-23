#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "DoublyLinked.h"

using namespace std;

template<typename T>
class LinkedQueue{
public:
  LinkedQueue();
  ~LinkedQueue();
  void enQueue(T e);
  void enQueue(Student* e);
  T deQueue();
  T peek();
  bool isEmpty();
private:
  int size;
  DoublyLinked<T>* d;
};

template<typename T>
LinkedQueue<T>::LinkedQueue(){
  d = new DoublyLinked<T>();
  size=0;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue(){
  delete d;
}

template<typename T>
void LinkedQueue<T>::enQueue(T e){
  d->insertBack(e);
  size++;
}

template<typename T>
void LinkedQueue<T>::enQueue(Student* e){
  d->insertBack(e);
  size++;
}

template<typename T>
T LinkedQueue<T>::deQueue(){
  if(!isEmpty()){
    size--;
    return d->removeFront();
  }else{
    throw "Empty Queue Exception";
  }
}

template<typename T>
T LinkedQueue<T>::peek(){
  if(!isEmpty()){
    return d->peekFront();
  }else{
    throw "Empty Queue Exception";
  }
}

template<typename T>
bool LinkedQueue<T>::isEmpty(){
  return (size==0);
}

#endif
