#include "Run.h"

Run::Run(){

}

Run::Run(int windows){
  windows = new int[windows];
  idle = new int[windows];
}

Run::~Run(){
  //delete
}

void Run::runTick(){
  for(int i=0;i<windows.size();++i){
    --windows[i];
    if(windows[i]<=0){
      if(Q.peek().timeAtWindow > 0){
        wait.insertBack(tick - Q.peek().timearrived);
        windows[i]=Q.deQueue();
      }else{
        idle[i]++;
      }
    }
  }

  tick++;
}

void Run::addToQ(int timearrived, int timeAtWindow){
  Q.enQueue(new Student(timearrived, timeAtWindow));
}

void Run::getStats(){
  int sum = 0;
  ListNode curr = wait->front;
  for(int i=0;i<wait.size;++i){
    sum+=curr.data;

  }
}
