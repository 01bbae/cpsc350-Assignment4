#include <iostream>
#include <fstream>
#include "Run.h"

using namespace std;

class IO{
public:
  IO();
  IO(string filename);
  ~IO();

private:
  ifstream ifs;
};
