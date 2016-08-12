#include <stdlib.h>
#include "systemc.h"
#include "test.h"

#define TOP test

using namespace sc_core;
using namespace std;
using namespace tlm;

int sc_main(int argc, char *argv[]) {
  
  TOP *inst_top = new TOP("top");

  srand(47);

  sc_start();

  delete inst_top;
  return 0;
}
