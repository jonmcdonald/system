#include "ethernet_packet.h"
#include "model_builder.h"

// Default constructor
ethernet_packet::ethernet_packet() {
  Clear();
  TimeStamp = sc_time_stamp();
}

// Constructor from an unsigned char array
ethernet_packet::ethernet_packet (unsigned char * newpacket, unsigned short size) {
  Clear();
  memcpy(packet, newpacket, size);
  setMacDestination(&packet[8]);
  setMacSource(&packet[14]);
  setPacketSize(&packet[20]);
  calcFcr();
  TimeStamp = sc_time_stamp();
}

// Contructor based of MAC addrsses
ethernet_packet::ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size) {
  Clear();
  setMacDestination(destination);
  setMacSource(source);
  setPayloadSize(new_payload_size);
  memcpy(&packet[22], new_payload, new_payload_size);
  calcFcr();
  TimeStamp = sc_time_stamp();
}

// set all values to defualts and an empty payload
void ethernet_packet::Clear() {
  for (unsigned int p = 0; p < 1526; p++) {
    if (p < 7) {
      packet[p] = 0x55;
    } else if (p == 7) {
      packet[p] = 0xD5;
    } else {
      packet[p] = 0;
    }
  }

  packet[20] = 0;
  packet[21] = 0x1A;
  mac_destination = 0;
  mac_source = 0; 
  payload_size = 0;
  TimeStamp = sc_time_stamp();
}

// Gets to the Preamble "0x55 0x55 0x55 0x55 0x55 0x55 0x55"
unsigned char * ethernet_packet::getPreamble() {
  unsigned char *newchar = new unsigned char[7];
  memcpy(newchar, packet, 7);
  return newchar;
}

// Gets the ethernet delimiter "0xD5"
unsigned char ethernet_packet::getDelimiter(){
  return packet[7];
}

// returns the packets desination MAC address as an unsigned long
unsigned long ethernet_packet::getMacDestination() {
  return mac_destination;
}

// sets the packets desination MAC address from an unsigned long
void ethernet_packet::setMacDestination(unsigned long Destination) {
  mac_destination = Destination;
  unsigned char *  cDestination = (unsigned char *)&mac_destination;
  packet[8]  = cDestination[5];
  packet[9]  = cDestination[4];
  packet[10] = cDestination[3];
  packet[11] = cDestination[2];
  packet[12] = cDestination[1];
  packet[13] = cDestination[0];
}

// sets the packets desination MAC address from an unsigned char array (size: 2 Bytes Big endian)
void ethernet_packet::setMacDestination(unsigned char * Destination) {
  memcpy(&packet[8], Destination, 6);
  unsigned char *  cDestination = (unsigned char *)&mac_destination;
  cDestination[7] = 0x0;
  cDestination[6] = 0x0;
  cDestination[5] = packet[8];
  cDestination[4] = packet[9];
  cDestination[3] = packet[10];
  cDestination[2] = packet[11];
  cDestination[1] = packet[12];
  cDestination[0] = packet[13];
}

// returns the packets source MAC address as an unsigned long
unsigned long ethernet_packet::getMacSource() {
  return mac_source;
}

// sets the packets source MAC address from an unsigned long
void ethernet_packet::setMacSource(unsigned long Source) {
  mac_source = Source;
  unsigned char *  cSource = (unsigned char *)&mac_source;
  packet[14] = cSource[5];
  packet[15] = cSource[4];
  packet[16] = cSource[3];
  packet[17] = cSource[2];
  packet[18] = cSource[1];
  packet[19] = cSource[0];
}

// sets the packets source MAC address from an unsigned char array (size: 2 Bytes Big endian)
void ethernet_packet::setMacSource(unsigned char * Source) {
  memcpy(&packet[14], Source, 6);
  unsigned char *  cSource = (unsigned char *)&mac_source;
  cSource[7] = 0x0;
  cSource[6] = 0x0;
  cSource[5] = packet[14];
  cSource[4] = packet[15];
  cSource[3] = packet[16];
  cSource[2] = packet[17];
  cSource[1] = packet[18];
  cSource[0] = packet[19];
}

// Gets the data payload (only) portion of the ethernet packet
unsigned char * ethernet_packet::getPayload() {
  if (payload_size > 0) {
    unsigned char *newchar = new unsigned char[payload_size];
    memcpy(newchar, &packet[22], payload_size);
    return newchar;
  } else {
    return (unsigned char *)NULL;
  }
}

// Sets the data payload (only) portion of the ethernet packet based on setPayloadSize()
void ethernet_packet::setPayload(unsigned char * payload){
  if (payload_size > 0) {
    memcpy(&packet[22], payload, payload_size);
  }
}

// Sets the data payload (only) size in bytes (Packet size will be Payload Size + 26)
unsigned short ethernet_packet::getPayloadSize() {
  return payload_size;
}

// Gets the data payload (only) size in bytes (Packet size will be Payload Size + 26)
void ethernet_packet::setPayloadSize(unsigned short newsize) {
  if (newsize > 1500) {
    payload_size = 1500;
  } else {
    payload_size = newsize;
  }
  unsigned short packet_size = payload_size +26;
  unsigned char * cpacket_size = (unsigned char *) &packet_size;
  packet[20] = cpacket_size[1];
  packet[21] = cpacket_size[0];
}

// Gets the Error Correct and Detection Value
unsigned short ethernet_packet::getFcr() {
  unsigned short fcr = 0x0;
  unsigned char * cfcr = (unsigned char *) &fcr;
  cfcr[0] = packet[payload_size + 25];
  cfcr[1] = packet[payload_size + 24];
  return fcr;
}

// Calulate Error Correct and Detection Value
void ethernet_packet::calcFcr() {
  // not implementoed at this point
}

// Returns a new unsigned char arrray containing the complete packet
unsigned char * ethernet_packet::getPacket() {
  unsigned char * newchar = new unsigned char[payload_size + 26];
  memcpy(newchar, packet, (unsigned int)(payload_size + 26));
  return newchar;
}

// Get the size of the total packet in bytes (Payload Size + 26)
unsigned short ethernet_packet::getPacketSize() {
  return payload_size + 26;
}

// sets the packet size from unsigned char (size: 2 Bytes Big endian)
void ethernet_packet::setPacketSize(unsigned char * newsize) {
  unsigned short size = 0;
  unsigned char * ssize = (unsigned char *) &size;
  ssize[1] = newsize[0];
  ssize[0] = newsize[1];
  if (size > 1526) {
    size = 1526;
  }
  payload_size = size - 26;
  packet[20] = ssize[1];
  packet[21] = ssize[0];
}

// Creats a NEW ethernet packet object instance based on the current object instance
void ethernet_packet::Print() {
  cout << "Packet Destination MAC: " << hex << mac_destination
       << "  Source MAC: " << hex<< mac_source
       << "  Size : " << dec << getPacketSize()
       << "  Time Stamp: " << TimeStamp << endl;
  //  for (unsigned int c = 0; c < getPacketSize(); c++) {
  //    cout << " 0x" << hex << (unsigned long)packet[c];
  //  }
  //  cout << endl;
}

// sends information to standard out based on the currect object instance
ethernet_packet * ethernet_packet::Clone() {
  ethernet_packet * new_packet = new ethernet_packet;
  memcpy(new_packet->packet, packet, 1526);
  new_packet->mac_destination = mac_destination;
  new_packet->mac_source = mac_source;
  new_packet->payload_size = payload_size;
  new_packet->TimeStamp = TimeStamp;
  calcFcr();
  
  return new_packet;
}
