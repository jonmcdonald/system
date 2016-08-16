
/**************************************************************/
/*                                                            */
/*      Copyright Mentor Graphics Corporation 2006 - 2015     */
/*                  All Rights Reserved                       */
/*                                                            */
/*       THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY      */
/*         INFORMATION WHICH IS THE PROPERTY OF MENTOR        */
/*         GRAPHICS CORPORATION OR ITS LICENSORS AND IS       */
/*                 SUBJECT TO LICENSE TERMS.                  */
/*                                                            */
/**************************************************************/

//*<
//* Generated By Model Builder, Mentor Graphics Computer Systems, Inc.
//*
//* This file contains the PV class for SystemControllerLevel1.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 4.2.1
//* Generated on: Aug. 15, 2016 12:30:04 PM, (user: kenm)
//*>



#include "SystemControllerLevel1_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
SystemControllerLevel1_pv::SystemControllerLevel1_pv(sc_module_name module_name) 
  : SystemControllerLevel1_pv_base(module_name) {
  ProcessFifo.set_minimal_delay(ProcessDelayInClocks *clock);
  ProcessFifo.nb_bound(ProcessFifoSize);
  max_sample = 0;
  min_sample = USHRT_MAX;

  SC_THREAD(ProcessThread);
}      

// Read callback for Slave port.
// Returns true when successful.
bool SystemControllerLevel1_pv::Slave_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

// Write callback for Slave port.
// Returns true when successful.
bool SystemControllerLevel1_pv::Slave_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  ethernet_packet * packet = new ethernet_packet(data, (unsigned short)size);
  if (ProcessFifo.nb_can_put()) {
    wait(size * clock * 8);
    ProcessFifo.put(packet);
    return true;
  } else {
    cout << sc_time_stamp() << "System Controller Fifo full, packet dropped" << endl;
  }
    
  return false;
} 




unsigned SystemControllerLevel1_pv::Slave_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned SystemControllerLevel1_pv::Slave_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool SystemControllerLevel1_pv::Slave_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}

 

// in order to minimize merging conflicts, we recommend to add your functions after this comment
void SystemControllerLevel1_pv::ProcessThread() {
  ethernet_packet * packet = new ethernet_packet();
  packet->set_mac_destination((unsigned long)0);
  packet->set_mac_source(MacAddress);
  packet->set_payload_size(0);
  packet->calc_fcr();
  mb_sync();
  packet->time_stamp = sc_time_stamp();

  unsigned char * ucpacket = packet->get_packet();
  Master_write(0, ucpacket, packet->get_packet_size());
  delete ucpacket;
  delete packet;

  while (true) {
    packet = ProcessFifo.get();

    unsigned long mac_source = packet->get_mac_source_as_long();

    unsigned short * samples = (unsigned short *)packet->get_payload();
    for (unsigned int nsample = 0; nsample < (unsigned int)(packet->get_payload_size() / 2); nsample++) {
      if (samples[nsample] > max_sample) {
        max_sample = samples[nsample];
      }
      if (samples[nsample] < min_sample) {
        min_sample = samples[nsample];
      }
    }

    unsigned short offset = (max_sample - min_sample) / 2;
    unsigned char * ucoffset = (unsigned char *) &offset;

    delete samples;
    delete packet;

    packet = new ethernet_packet(mac_source, MacAddress, (unsigned char *) ucoffset, 2);
    unsigned char * ucpacket = packet->get_packet();
    Master_write(mac_source, ucpacket, packet->get_packet_size());

    delete packet;
  }
}
