
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
//* This file contains the PV class for NetworkSwitchLevel1.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 4.2.1
//* Generated on: Aug. 15, 2016 12:15:23 PM, (user: kenm)
//* Automatically merged on: Aug. 15, 2016 10:47:09 PM, (user: kenm)
//* Automatically merged on: Aug. 15, 2016 10:47:54 PM, (user: kenm)
//*>



#include "NetworkSwitchLevel1_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
NetworkSwitchLevel1_pv::NetworkSwitchLevel1_pv(sc_module_name module_name) 
  : NetworkSwitchLevel1_pv_base(module_name) {
  NodeFifo0.set_minimal_delay(WireDelay); // Set Delay time which is from the time an packet is put int the fifo to when it can be removed
  NodeFifo1.set_minimal_delay(WireDelay); // Set Delay time which is from the time an packet is put int the fifo to when it can be removed
  NodeFifo2.set_minimal_delay(WireDelay); // Set Delay time which is from the time an packet is put int the fifo to when it can be removed
  NodeFifo3.set_minimal_delay(WireDelay); // Set Delay time which is from the time an packet is put int the fifo to when it can be removed
  NodeFifo4.set_minimal_delay(WireDelay); // Set Delay time which is from the time an packet is put int the fifo to when it can be removed

  SC_THREAD(NodeThread0); // Start Node0 Fifo which forwards packets from NodeFifo4 to NodeMaster0 port
  SC_THREAD(NodeThread1); // Start Node1 Fifo which forwards packets from NodeFifo4 to NodeMaster1 port
  SC_THREAD(NodeThread2); // Start Node2 Fifo which forwards packets from NodeFifo4 to NodeMaster2 port
  SC_THREAD(NodeThread3); // Start Node3 Fifo which forwards packets from NodeFifo4 to NodeMaster3 port
  SC_THREAD(NodeThread4); // Start Node4 Fifo which forwards packets from NodeFifo4 to NodeMaster4 port

  PortWidthFactor[0] = getSystemCBaseModel()->get_port_width(NodeSlave0_idx) * 8;
  PortWidthFactor[1] = getSystemCBaseModel()->get_port_width(NodeSlave1_idx) * 8;
  PortWidthFactor[2] = getSystemCBaseModel()->get_port_width(NodeSlave2_idx) * 8;
  PortWidthFactor[3] = getSystemCBaseModel()->get_port_width(NodeSlave3_idx) * 8;
  PortWidthFactor[4] = getSystemCBaseModel()->get_port_width(NodeSlave4_idx) * 8;
  PortClock[0] = sc_time(1, SC_PS) * getSystemCBaseModel()->get_clock(NodeSlave0_idx) ;
  PortClock[1] = sc_time(1, SC_PS) * getSystemCBaseModel()->get_clock(NodeSlave1_idx) ;
  PortClock[2] = sc_time(1, SC_PS) * getSystemCBaseModel()->get_clock(NodeSlave2_idx) ;
  PortClock[3] = sc_time(1, SC_PS) * getSystemCBaseModel()->get_clock(NodeSlave3_idx) ;
  PortClock[4] = sc_time(1, SC_PS) * getSystemCBaseModel()->get_clock(NodeSlave4_idx) ;
  DropRate = 0.0;
}      

// Read callback for NodeSlave0 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave0_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}


// Read callback for NodeSlave1 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave1_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}


// Read callback for NodeSlave2 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave2_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}


// Read callback for NodeSlave3 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave3_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}


// Read callback for NodeSlave4 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave4_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

// Write callback for NodeSlave0 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave0_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  unsigned int t = size * PortWidthFactor[0];
  wait( t * PortClock[0] );
  return send_packet(NodeMaster0_idx, address, data, size);
} 

// Write callback for NodeSlave1 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave1_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  unsigned int t = size * PortWidthFactor[1];
  wait( t * PortClock[1] );
  return send_packet(NodeMaster1_idx, address, data, size);
} 

// Write callback for NodeSlave2 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave2_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  unsigned int t = size * PortWidthFactor[2];
  wait( t * PortClock[2] );
  return send_packet(NodeMaster2_idx, address, data, size);
} 

// Write callback for NodeSlave3 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave3_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  unsigned int t = size * PortWidthFactor[3];
  wait( t * PortClock[3] );
  return send_packet(NodeMaster3_idx, address, data, size); 
} 

// Write callback for NodeSlave4 port.
// Returns true when successful.
bool NetworkSwitchLevel1_pv::NodeSlave4_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  unsigned int t = size * PortWidthFactor[4];
  wait( t * PortClock[4] );
  return send_packet(NodeMaster4_idx, address, data, size);
} 




unsigned NetworkSwitchLevel1_pv::NodeSlave0_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned NetworkSwitchLevel1_pv::NodeSlave0_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool NetworkSwitchLevel1_pv::NodeSlave0_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}





unsigned NetworkSwitchLevel1_pv::NodeSlave1_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned NetworkSwitchLevel1_pv::NodeSlave1_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool NetworkSwitchLevel1_pv::NodeSlave1_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}





unsigned NetworkSwitchLevel1_pv::NodeSlave2_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned NetworkSwitchLevel1_pv::NodeSlave2_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool NetworkSwitchLevel1_pv::NodeSlave2_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}





unsigned NetworkSwitchLevel1_pv::NodeSlave3_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned NetworkSwitchLevel1_pv::NodeSlave3_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool NetworkSwitchLevel1_pv::NodeSlave3_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}





unsigned NetworkSwitchLevel1_pv::NodeSlave4_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned NetworkSwitchLevel1_pv::NodeSlave4_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool NetworkSwitchLevel1_pv::NodeSlave4_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}

 

// in order to minimize merging conflicts, we recommend to add your functions after this comment

// Send packets out master port using port Fifo.
bool NetworkSwitchLevel1_pv::send_packet(unsigned long master_port_index, mb_address_type address, unsigned char * data, unsigned int size) {
  if (size > 1526) { // check for valid packet size
    return false; // packet larger than standard packet (This doesn't support jumbo packets)
  }

  // create a ethernet packet from the incoming data
  ethernet_packet * packet = new ethernet_packet(data, (unsigned short)size);

  // check for correct Destination and source mack addresses (> 0)
  if ((packet->getMacDestination() <= 0) || (packet->getMacSource() <= 0)) {
    cout << sc_time_stamp() << " ***** Bad source or destination address in packet. Packet Dropped *****" << endl;
    delete packet;
    return false;
  }

  // check to see if the source MAC address is in the Map table.
  std::map<unsigned long, unsigned long>::iterator key_value = MacAddressMap.find(packet->getMacSource());

  if (key_value == MacAddressMap.end()) { // Find returns end of map iterater if the item isn't found
    if (MacAddressMap.size() >= MaxMapTableSize) { // chech to see if there is space left in the Map table
      delete packet;
      return false; // exceeded the maximum table size. Note:: A scrubing routine should be added.
    } else { // if there is ad the new map entry. Key is the destination MAC address and the value is the port it is connected to.
      // Note: this will even work through another switch.
      MacAddressMap[packet->getMacSource()] = master_port_index;
    }
  }

  // check to see if the destination MAC address is in the Map table.
  key_value = MacAddressMap.find(packet->getMacDestination());
  if (key_value == MacAddressMap.end()) { // If not in Mac Map Table then broadcast to everyone
    NodeFifoPut(NodeMaster0_idx, packet->Clone()); // create clone of packet so each has it own vertion of the  packet
    NodeFifoPut(NodeMaster1_idx, packet->Clone()); // create clone of packet so each has it own vertion of the  packet
    NodeFifoPut(NodeMaster2_idx, packet->Clone()); // create clone of packet so each has it own vertion of the  packet
    NodeFifoPut(NodeMaster3_idx, packet->Clone()); // create clone of packet so each has it own vertion of the  packet
    NodeFifoPut(NodeMaster4_idx, packet); // send the existing packet
  } else { // else send the packet to the destination port based on the MAC map table.
    unsigned long port_index = key_value->second;
    NodeFifoPut(port_index, packet); // send the existing packet
  }
  return true;
}

// Puts the packet into the port Fifo
bool NetworkSwitchLevel1_pv::NodeFifoPut(unsigned int port_index, ethernet_packet * packet) {
  // else send the packet to the destination port based on the MAC map table.
  if (port_index == NodeMaster0_idx) { // If Mode  Master
    if (NodeFifo0.nb_can_put()) {      // Check to see in there is room in the fifo
      NodeFifo0.put(packet);           // put the packet into the Node 0 Fifo
      DropRate = DropRate * 0.8; ppassed++;
    } else {
      delete packet;                   // throw out the packet if there isn't space
      DropRate = (DropRate * 0.8) + 50.0; pdropped++;
      return false;
    }
  } else if (port_index == NodeMaster1_idx) { // If Mode 1 Master
    if (NodeFifo1.nb_can_put()) {      // Check to see in there is room in the fifo
      NodeFifo1.put(packet);           // put the packet into the Node 1 Fifo
      DropRate = DropRate * 0.8; ppassed++;
    } else {
      delete packet;                   // throw out the packet if there isn't space
      DropRate = (DropRate * 0.8) + 50.0; pdropped++;
      return false;
    }
  } else if (port_index == NodeMaster2_idx) { // If Mode 2 Master
    if (NodeFifo2.nb_can_put()) {      // Check to see in there is room in the fifo
      NodeFifo2.put(packet);           // put the packet into the Node 2 Fifo
      DropRate = DropRate * 0.8; ppassed++;
    } else {
      delete packet;                   // throw out the packet if there isn't space
      DropRate = (DropRate * 0.8) + 50.0; pdropped++;
      return false;
    }
  } else if (port_index == NodeMaster3_idx) { // If Mode 3 Master
    if (NodeFifo3.nb_can_put()) {      // Check to see in there is room in the fifo
      NodeFifo3.put(packet);           // put the packet into the Node 3 Fifo
      DropRate = DropRate * 0.8; ppassed++;
    } else {
      delete packet;                   // throw out the packet if there isn't space
      DropRate = (DropRate * 0.8) + 50.0; pdropped++;
      return false;
    }
  } else if (port_index == NodeMaster4_idx) { // If Mode 0 Master
    if (NodeFifo4.nb_can_put()) {      // Check to see in there is room in the fifo
      NodeFifo4.put(packet);           // put the packet into the Node 3 Fifo
      DropRate = DropRate * 0.8; ppassed++;
    } else {
      delete packet;                   // throw out the packet if there isn't space
      DropRate = (DropRate * 0.8) + 50.0; pdropped++;
      return false;
    }
  } else {
    delete packet;                     // throw out the packet if destination port isn't found
  }
  return true;
}


// Thread which forwards packets from NodeFifo0 to NodeMaster0 port
void NetworkSwitchLevel1_pv::NodeThread0() {
  while (true) { // Run Forever
    ethernet_packet * packet = NodeFifo0.get(); // Get next packet from Fifo
    unsigned char * ucpacket = packet->getPacket(); // convert packet object to unsigned char array

    // Write coverted (unsigned char array) packet data to port
    NodeMaster0_write(packet->getMacDestination(), ucpacket, packet->getPacketSize());
    
    // delete the data unsigned char array (the GetPadket creats a NEW char array with needs to be deleted afeter use)
    delete ucpacket;

    // delete the send packet object
    delete packet;
  }
}

// Thread which forwards packets from NodeFifo1 to NodeMaster2 port
void NetworkSwitchLevel1_pv::NodeThread1() {
  while (true) { // Run Forever
    ethernet_packet * packet = NodeFifo1.get(); // Get next packet from Fifo
    unsigned char * ucpacket = packet->getPacket(); // convert packet object to unsigned char array

    // Write coverted (unsigned char array) packet data to port
    NodeMaster1_write(packet->getMacDestination(), ucpacket, packet->getPacketSize());

    // delete the data unsigned char array (the GetPadket creats a NEW char array with needs to be deleted afeter use)
    delete ucpacket;

    // delete the send packet object
    delete packet;
  }
}

// Thread which forwards packets from NodeFifo2 to NodeMaster2 port
void NetworkSwitchLevel1_pv::NodeThread2() {
  while (true) { // Run Forever
    ethernet_packet * packet = NodeFifo2.get(); // Get next packet from Fifo
    unsigned char * ucpacket = packet->getPacket(); // convert packet object to unsigned char array

    // Write coverted (unsigned char array) packet data to port
    NodeMaster2_write(packet->getMacDestination(), ucpacket, (unsigned int)packet->getPacketSize());

    // delete the data unsigned char array (the GetPadket creats a NEW char array with needs to be deleted afeter use)
    delete ucpacket;

    // delete the send packet object
    delete packet;
  }
}

// Thread which forwards packets from NodeFifo3 to NodeMaster3 port
void NetworkSwitchLevel1_pv::NodeThread3() {
  while (true) { // Run Forever
    ethernet_packet * packet = NodeFifo3.get(); // Get next packet from Fifo
    unsigned char * ucpacket = packet->getPacket(); // convert packet object to unsigned char array

    // Write coverted (unsigned char array) packet data to port
    NodeMaster3_write(packet->getMacDestination(), ucpacket, packet->getPacketSize());

    // delete the data unsigned char array (the GetPadket creats a NEW char array with needs to be deleted afeter use)
    delete ucpacket;

    // delete the send packet object
    delete packet;
  }
}

// Thread which forwards packets from NodeFifo4 to NodeMaster4 port
void NetworkSwitchLevel1_pv::NodeThread4() {
  while (true) { // Run Forever
    ethernet_packet * packet = NodeFifo4.get(); // Get next packet from Fifo
    unsigned char * ucpacket = packet->getPacket(); // convert packet object to unsigned char array

    // Write coverted (unsigned char array) packet data to port
    NodeMaster4_write(packet->getMacDestination(), ucpacket, packet->getPacketSize());

    // delete the data unsigned char array (the GetPadket creats a NEW char array with needs to be deleted afeter use)
    delete ucpacket;

    // delete the send packet object
    delete packet;
  }
}

void NetworkSwitchLevel1_pv::end_of_simulation() {
  cout <<name()<<": "<<ppassed<<" packets passed, "<<pdropped<<" dropped\n";
}
