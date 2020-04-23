#ifndef LISTNODE_H
#define LISTNODE_H
#include <cstddef>

using namespace std;

template<typename T>
class ListNode{
public:
  ListNode();
  ListNode(T d);
  ~ListNode();
  T data;
  ListNode* next;
  ListNode* prev;
};

template<typename T>
ListNode<T>::ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

template<typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
  //delete
}

#endif
