#pragma once
#include "mgc_vista_schematics.h"
$includes_begin;
#include <systemc.h>
#include "../SharedModels/WaveSampleGenerator_model.h"
#include "../ModelsLevel1/NetworkSwitchLevel1_model.h"
#include "../ModelsLevel1/SystemControllerLevel1_model.h"
#include "../ModelsLevel1/SensorNodeLevel1_model.h"
$includes_end;

$module_begin("TopLevel1");
SC_MODULE(TopLevel1) {
public:
  typedef TopLevel1 SC_CURRENT_USER_MODULE;
  TopLevel1(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("WAVE3"),
WAVE3(0)
$end
$init("NETWORKSWITCH"),
NETWORKSWITCH(0)
$end
$init("SYSTEMCONTROLLER"),
SYSTEMCONTROLLER(0)
$end
$init("WAVE2"),
WAVE2(0)
$end
$init("NODE3"),
NODE3(0)
$end
$init("WAVE1"),
WAVE1(0)
$end
$init("NODE2"),
NODE2(0)
$end
$init("WAVE0"),
WAVE0(0)
$end
$init("NODE1"),
NODE1(0)
$end
$init("NODE0"),
NODE0(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("WAVE3");
WAVE3 = new WaveSampleGenerator_pvt("WAVE3");
$end;
$create_component("NETWORKSWITCH");
NETWORKSWITCH = new NetworkSwitchLevel1_pvt("NETWORKSWITCH");
$end;
$create_component("SYSTEMCONTROLLER");
SYSTEMCONTROLLER = new SystemControllerLevel1_pvt("SYSTEMCONTROLLER");
$end;
$create_component("WAVE2");
WAVE2 = new WaveSampleGenerator_pvt("WAVE2");
$end;
$create_component("NODE3");
NODE3 = new SensorNodeLevel1_pvt("NODE3");
$end;
$create_component("WAVE1");
WAVE1 = new WaveSampleGenerator_pvt("WAVE1");
$end;
$create_component("NODE2");
NODE2 = new SensorNodeLevel1_pvt("NODE2");
$end;
$create_component("WAVE0");
WAVE0 = new WaveSampleGenerator_pvt("WAVE0");
$end;
$create_component("NODE1");
NODE1 = new SensorNodeLevel1_pvt("NODE1");
$end;
$create_component("NODE0");
NODE0 = new SensorNodeLevel1_pvt("NODE0");
$end;
$bind("NODE2->Sensor","WAVE2->Slave");
vista_bind(NODE2->Sensor, WAVE2->Slave);
$end;
$bind("NODE0->Sensor","WAVE0->Slave");
vista_bind(NODE0->Sensor, WAVE0->Slave);
$end;
$bind("NODE3->Sensor","WAVE3->Slave");
vista_bind(NODE3->Sensor, WAVE3->Slave);
$end;
$bind("NODE1->Sensor","WAVE1->Slave");
vista_bind(NODE1->Sensor, WAVE1->Slave);
$end;
$bind("NODE3->NetworkMaster","NETWORKSWITCH->NodeSlave3");
vista_bind(NODE3->NetworkMaster, NETWORKSWITCH->NodeSlave3);
$end;
$bind("NODE2->NetworkMaster","NETWORKSWITCH->NodeSlave2");
vista_bind(NODE2->NetworkMaster, NETWORKSWITCH->NodeSlave2);
$end;
$bind("NETWORKSWITCH->NodeMaster3","NODE3->NetworkSlave");
vista_bind(NETWORKSWITCH->NodeMaster3, NODE3->NetworkSlave);
$end;
$bind("NODE1->NetworkMaster","NETWORKSWITCH->NodeSlave1");
vista_bind(NODE1->NetworkMaster, NETWORKSWITCH->NodeSlave1);
$end;
$bind("NETWORKSWITCH->NodeMaster1","NODE1->NetworkSlave");
vista_bind(NETWORKSWITCH->NodeMaster1, NODE1->NetworkSlave);
$end;
$bind("NODE0->NetworkMaster","NETWORKSWITCH->NodeSlave0");
vista_bind(NODE0->NetworkMaster, NETWORKSWITCH->NodeSlave0);
$end;
$bind("NETWORKSWITCH->NodeMaster0","NODE0->NetworkSlave");
vista_bind(NETWORKSWITCH->NodeMaster0, NODE0->NetworkSlave);
$end;
$bind("NETWORKSWITCH->NodeMaster2","NODE2->NetworkSlave");
vista_bind(NETWORKSWITCH->NodeMaster2, NODE2->NetworkSlave);
$end;
$bind("NETWORKSWITCH->NodeMaster4","SYSTEMCONTROLLER->Slave");
vista_bind(NETWORKSWITCH->NodeMaster4, SYSTEMCONTROLLER->Slave);
$end;
$bind("SYSTEMCONTROLLER->Master","NETWORKSWITCH->NodeSlave4");
vista_bind(SYSTEMCONTROLLER->Master, NETWORKSWITCH->NodeSlave4);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "SchematicsLevel1";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~TopLevel1() {
    $destructor_begin;
$destruct_component("WAVE3");
delete WAVE3; WAVE3 = 0;
$end;
$destruct_component("NETWORKSWITCH");
delete NETWORKSWITCH; NETWORKSWITCH = 0;
$end;
$destruct_component("SYSTEMCONTROLLER");
delete SYSTEMCONTROLLER; SYSTEMCONTROLLER = 0;
$end;
$destruct_component("WAVE2");
delete WAVE2; WAVE2 = 0;
$end;
$destruct_component("NODE3");
delete NODE3; NODE3 = 0;
$end;
$destruct_component("WAVE1");
delete WAVE1; WAVE1 = 0;
$end;
$destruct_component("NODE2");
delete NODE2; NODE2 = 0;
$end;
$destruct_component("WAVE0");
delete WAVE0; WAVE0 = 0;
$end;
$destruct_component("NODE1");
delete NODE1; NODE1 = 0;
$end;
$destruct_component("NODE0");
delete NODE0; NODE0 = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$component("WAVE3");
WaveSampleGenerator_pvt *WAVE3;
$end;
$component("NETWORKSWITCH");
NetworkSwitchLevel1_pvt *NETWORKSWITCH;
$end;
$component("SYSTEMCONTROLLER");
SystemControllerLevel1_pvt *SYSTEMCONTROLLER;
$end;
$component("WAVE2");
WaveSampleGenerator_pvt *WAVE2;
$end;
$component("NODE3");
SensorNodeLevel1_pvt *NODE3;
$end;
$component("WAVE1");
WaveSampleGenerator_pvt *WAVE1;
$end;
$component("NODE2");
SensorNodeLevel1_pvt *NODE2;
$end;
$component("WAVE0");
WaveSampleGenerator_pvt *WAVE0;
$end;
$component("NODE1");
SensorNodeLevel1_pvt *NODE1;
$end;
$component("NODE0");
SensorNodeLevel1_pvt *NODE0;
$end;
  $fields_end;
  $vlnv_decl_begin;
public:
const char* m_library;
const char* m_vendor;
const char* m_version;
  $vlnv_decl_end;
};
$module_end;