#include "IO.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  if(argc==2){
    IO *i = new IO(argv[1]);
    delete i;
  }

  return 0;
}
