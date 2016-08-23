//v2: comments beginning with v2 are generated and used by V2
//v2: please don't remove or modify these comments

#include <stdlib.h>
//v2: begin of includes section
#include "TopLevel1.h"
//v2: end of includes section

int sc_main(int argc, char *argv[]) {

//v2: begin of channel declarations section
//v2: end of channel declarations section

  srand(47);

//v2: begin of instantiations section
//v2: instance inst_TopLevel1 - instance number 0 of module TopLevel1
TopLevel1 *inst_TopLevel1 = new TopLevel1("TopLevel1");
//v2: end of instantiations section


//v2: begin of ports assignment section
//v2: ports assignment for instance inst_TopLevel1
//v2: end of ports assignment section

 sc_start();

 if (not sc_end_of_simulation_invoked()) {
   cout<< "Explicitly calling sc_stop\n";
   sc_stop();
 }

//v2: begin of instantiations section
delete inst_TopLevel1;
//v2: end of instantiations section

 return 0;
}
