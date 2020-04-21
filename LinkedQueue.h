#include "DoublyLinked.h"

template<typename T>
class LinkedQueue{
public:
  LinkedQueue();
  ~LinkedQueue();
  void enQueue(T e);
  T deQueue();
  T peek();
  bool isEmpty();
private:
  int size;
  DoublyLinked* d;
};

template<typename T>
LinkedQueue::LinkedQueue(){
  d = new DoublyLinked();
  size=0;
}

template<typename T>
LinkedQueue::~LinkedQueue(){
  delete d;
}

template<typename T>
void LinkedQueue::enQueue(T e){
  d.insertBack(e);
  size++;
}

template<typename T>
T LinkedQueue::deQueue(){
  if(!isEmpty()){
    size--;
    return d.removeFront();
  }
  return -1;
}

template<typename T>
T LinkedQueue::deQueue(){
  if(!isEmpty()){
    return d.peek();
  }
  return -1;
}

template<typename T>
bool LinkedQueue::isEmpty(){
  return (size==0);
}
