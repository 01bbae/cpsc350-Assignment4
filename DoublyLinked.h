#include "ListNode.h"

template<typename T>
class DoublyLinked{
public:
  DoublyLinked();
  ~DoublyLinked();
  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeAtPos(int pos);
  T peekFront();
  //int search(T d);
  bool isEmpty();
  int size;
private:
  ListNode front;
  ListNode rear;

};

template<typename T>
DoublyLinked<T>::DoublyLinked(){
  size = 0;
  front = NULL;
  rear = NULL;
}

template<typename T>
DoublyLinked<T>::~DoublyLinked(){
  while(!isEmpty()){
    removeFront();
  }
}

template<typename T>
void DoublyLinked<T>::insertFront(T d){
  if(isEmpty()){
    front = new ListNode<T>(d);
    rear = front;
  }else{
    ListNode temp = new ListNode(T d);
    temp->next = front;
    front->prev = temp;
    front = temp;
    delete temp;
  }
  size++;
}

template<typename T>
void DoublyLinked<T>::insertBack(){
  if(isEmpty()){
    front = new ListNode<T>(d);
    rear = front;
  }else{
    rear->next = new ListNode<T>(d);
    rear->next->prev = rear;
  }
  size++;
}

template<typename T>
T DoublyLinked<T>::removeFront(){
  if(!isEmpty()){
    size--;
    ListNode temp = front;
    T d = temp->data;
    front = temp->next;
    temp->next = NULL;
    delete temp;
    return d;
  }
  return -1;
}

template<typename T>
T DoublyLinked<T>::removeAtPos(int pos){
  if(!isEmpty() && pos < size-1){
    size--;
    ListNode curr = front;
    int count = 0;
    while(curr != NULL){
      if(pos==count){
        ListNode temp = curr;
        T d = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
        return d;
      }else{
        curr = curr->next;
        count++;
      }
    }
  }
  return -1;
}

template<typename T>
T DoublyLinked<T>::peekFront(){
  if(!isEmpty()){
    return front;
  }
  return -1;
}

template<typename T>
bool DoublyLinked<T>::isEmpty(){
  return (size==0);
}
