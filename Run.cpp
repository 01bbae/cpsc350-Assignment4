#include "Run.h"

Run::Run(){
  windowsize=0;
}

Run::Run(int window){
  windows = new int[window];
  idle = new int[window];
  windowsize=window;
  Q = new LinkedQueue<int>();
  arrive = new LinkedQueue<int>();
  wait = new DoublyLinked<int>();
}

Run::~Run(){
  delete windows;
  delete idle;
  delete Q;
  delete wait;
  delete arrive;
}

void Run::runTick(){
  try{
    for(int i=0;i<windowsize;++i){
      --windows[i]; //decrease time needed on windows
      if(windows[i]<=0){
        if(!Q->isEmpty()){
          windows[i]=Q->peek();
          Q->deQueue();
          cout << tick << endl;
          cout << arrive->peek() << endl;
          cout << "-----------------" <<endl;
          wait->insertBack(tick-arrive->deQueue());
        }else{
          idle[i]++;
        }
      }
    }

    tick++;
  }catch(const char* msg){
    cerr << msg << endl;
  }
}

void Run::addToQ(int timearrived, int timeAtWindow){
  Q->enQueue(timeAtWindow);
  arrive->enQueue(timearrived);
}

void Run::getStats(){
  int studentsum = 0;
  int count = 0;
  int median = 0;
  int tenplus = 0;
  ListNode<int>* curr = wait->front;
  int max = curr->data;
  for(int i=0;i<wait->size;++i){
    studentsum+=curr->data;
    count++;
    if(max<curr->data){
      max = curr->data;
    }
    if(curr->data > 10){
      tenplus++;
    }
    //include median
  }
  cout << "mean wait time: " << (double) studentsum/count << endl;
  cout << "longest student wait time: " << max <<endl;
  cout << "number of students waiting over 10 minutes: " << tenplus << endl;

  int windowsum = 0;
  int windowmax = idle[0];
  int fiveplus = 0;
  for(int i=0;i<windowsize;++i){
    windowsum+=idle[i];
    if(windowmax<idle[i]){
      windowmax=idle[i];
    }
    if(idle[i]>5){
      fiveplus++;
    }
  }

  cout << "mean idle time: " << (double) windowsum/windowsize << endl;
  cout << "longest idle time: " << windowmax << endl;
  cout << "number of windows idle for over 5 minutes: " << fiveplus << endl;
}
