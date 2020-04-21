#include "IO.h"

IO::IO(){
  //default constructor

}

IO::IO(string filename){
  ifs.open(filename);
  if(!ifs.is_open()){
    cout << "File does not exist" << endl;
  }else{
    int windows;
    int time;
    int numStudents;
    int timeAtWindow;
    ifs >> windows;
    ifs >> time;
    ifs >> numStudents;
    Run* r = new Run(windows);

    for(int i=0; i<numStudents; ++i){
      ifs>>timeAtWindow;
      r.addToQ(timeAtWindow);
    }
    r.runTick();

    while(!ifs.eof()){
      ifs >> time;
      ifs >> numStudents;
      if(Run.tick == time){
        for(int i=0; i<numStudents; ++i){
          ifs>>timeAtWindow;
          r.addToQ(time, timeAtWindow);
        }
      }
      r.runTick();
    }

  }


}

IO::~IO(){
  //delete
}
