#include "IO.h"

class Run{
public:
  Run();
  Run(int windows);
  ~Run();
  runTick(int time);
  addToQ(int time);
  int tick;
private:
  LinkedQueue* q;
  int* windows;
  int* idle;
  DoublyLinked* wait;
}
