#pragma once
#include "mgc_vista_schematics.h"
$includes_begin;
#include <systemc.h>
#include "../models/eth_model.h"
#include "../models/node_model.h"
$includes_end;

$module_begin("test");
SC_MODULE(test) {
public:
  typedef test SC_CURRENT_USER_MODULE;
  test(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("eth"),
eth(0)
$end
$init("node2"),
node2(0)
$end
$init("node3"),
node3(0)
$end
$init("node4"),
node4(0)
$end
$init("node5"),
node5(0)
$end
$init("node0"),
node0(0)
$end
$init("node1"),
node1(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("eth");
eth = new eth_pvt("eth");
$end;
$create_component("node2");
node2 = new node_pvt("node2");
$end;
$create_component("node3");
node3 = new node_pvt("node3");
$end;
$create_component("node4");
node4 = new node_pvt("node4");
$end;
$create_component("node5");
node5 = new node_pvt("node5");
$end;
$create_component("node0");
node0 = new node_pvt("node0");
$end;
$create_component("node1");
node1 = new node_pvt("node1");
$end;
$bind("eth->r0","node0->s");
vista_bind(eth->r0, node0->s);
$end;
$bind("eth->r1","node1->s");
vista_bind(eth->r1, node1->s);
$end;
$bind("node1->y","eth->d1");
vista_bind(node1->y, eth->d1);
$end;
$bind("eth->r2","node2->s");
vista_bind(eth->r2, node2->s);
$end;
$bind("node3->y","eth->d3");
vista_bind(node3->y, eth->d3);
$end;
$bind("node5->y","eth->d5");
vista_bind(node5->y, eth->d5);
$end;
$bind("eth->r3","node3->s");
vista_bind(eth->r3, node3->s);
$end;
$bind("node0->y","eth->d0");
vista_bind(node0->y, eth->d0);
$end;
$bind("eth->r4","node4->s");
vista_bind(eth->r4, node4->s);
$end;
$bind("node2->y","eth->d2");
vista_bind(node2->y, eth->d2);
$end;
$bind("eth->r5","node5->s");
vista_bind(eth->r5, node5->s);
$end;
$bind("node4->y","eth->d4");
vista_bind(node4->y, eth->d4);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "local";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~test() {
    $destructor_begin;
$destruct_component("eth");
delete eth; eth = 0;
$end;
$destruct_component("node2");
delete node2; node2 = 0;
$end;
$destruct_component("node3");
delete node3; node3 = 0;
$end;
$destruct_component("node4");
delete node4; node4 = 0;
$end;
$destruct_component("node5");
delete node5; node5 = 0;
$end;
$destruct_component("node0");
delete node0; node0 = 0;
$end;
$destruct_component("node1");
delete node1; node1 = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$component("eth");
eth_pvt *eth;
$end;
$component("node2");
node_pvt *node2;
$end;
$component("node3");
node_pvt *node3;
$end;
$component("node4");
node_pvt *node4;
$end;
$component("node5");
node_pvt *node5;
$end;
$component("node0");
node_pvt *node0;
$end;
$component("node1");
node_pvt *node1;
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