#ifndef RUN_H
#define RUN_H
#include "Student.h"
#include "LinkedQueue.h"

using namespace std;

class Run{
public:
  Run();
  Run(int window);
  ~Run();
  void runTick();
  void addToQ(int timearrived, int timeAtWindow);
  void getStats();
  int tick;
private:
  LinkedQueue<int>* Q;
  int* windows;
  int* idle;
  LinkedQueue<int>* arrive;
  DoublyLinked<int>* wait;
  int windowsize;
  int waitsize;
};

#endif
