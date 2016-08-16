#include "ethernet_packet.h"
#include "model_builder.h"


ethernet_packet::ethernet_packet() {
  clear();
  time_stamp = sc_time_stamp();
  status = normal;
}

ethernet_packet::ethernet_packet (unsigned char * newpacket, unsigned short size) {
  clear();
  memcpy(packet, newpacket, size);
  set_mac_destination(&packet[8]);
  set_mac_source(&packet[14]);
  set_packet_size(&packet[20]);
  calc_fcr();
  time_stamp = sc_time_stamp();
}

ethernet_packet::ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size) {
  clear();
  set_mac_destination(destination);
  set_mac_source(source);
  set_payload_size(new_payload_size);
  memcpy(&packet[22], new_payload, new_payload_size);
  calc_fcr();
  time_stamp = sc_time_stamp();
}

ethernet_packet::ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size, unsigned short new_failed_size) {
  clear();
  set_mac_destination(destination);
  set_mac_source(source);
  set_payload_size(new_payload_size);
  memcpy(&packet[22], new_payload, new_payload_size);
  calc_fcr();
  set_failed_size(new_failed_size);
  time_stamp = sc_time_stamp();
}

void ethernet_packet::clear() {
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
  failed_size = 0;
  time_stamp = sc_time_stamp();
}

unsigned char * ethernet_packet::get_preamble() {
  unsigned char *newchar = new unsigned char[7];
  memcpy(newchar, packet, 7);
  return newchar;
}

unsigned char ethernet_packet::get_start_of_frame_delimiter(){
  return packet[7];
}

unsigned long ethernet_packet::get_mac_destination_as_long() {
  return mac_destination;
}

unsigned char * ethernet_packet::get_mac_destination_as_char() {
  unsigned char *newchar = new unsigned char[6];
  memcpy(newchar, &packet[8], 6);
  return newchar;
}

void ethernet_packet::set_mac_destination(unsigned long Destination) {
  mac_destination = Destination;
  unsigned char *  cDestination = (unsigned char *)&mac_destination;
  packet[8]  = cDestination[5];
  packet[9]  = cDestination[4];
  packet[10] = cDestination[3];
  packet[11] = cDestination[2];
  packet[12] = cDestination[1];
  packet[13] = cDestination[0];
}

void ethernet_packet::set_mac_destination(unsigned char * Destination) {
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

unsigned long ethernet_packet::get_mac_source_as_long() {
  return mac_source;
}

unsigned char * ethernet_packet::get_mac_source_as_char() {
  unsigned char *newchar = new unsigned char[6];
  memcpy(newchar, &packet[14], 6);
  return newchar;
}

void ethernet_packet::set_mac_source(unsigned long Source) {
  mac_source = Source;
  unsigned char *  cSource = (unsigned char *)&mac_source;
  packet[14] = cSource[5];
  packet[15] = cSource[4];
  packet[16] = cSource[3];
  packet[17] = cSource[2];
  packet[18] = cSource[1];
  packet[19] = cSource[0];
}

void ethernet_packet::set_mac_source(unsigned char * Source) {
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

unsigned char * ethernet_packet::get_payload() {
  if (payload_size > 0) {
    unsigned char *newchar = new unsigned char[payload_size];
    memcpy(newchar, &packet[22], payload_size);
    return newchar;
  } else {
    return (unsigned char *)NULL;
  }
}

void ethernet_packet::set_payload(unsigned char * payload){
  if (payload_size > 0) {
    memcpy(&packet[22], payload, payload_size);
  }
}

unsigned short ethernet_packet::get_payload_size() {
  return payload_size;
}

void ethernet_packet::set_payload_size(unsigned short newsize) {
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

unsigned short ethernet_packet::get_fcr() {
  unsigned short fcr = 0x0;
  unsigned char * cfcr = (unsigned char *) &fcr;
  cfcr[0] = packet[payload_size + 25];
  cfcr[1] = packet[payload_size + 24];
  return fcr;
}

unsigned char * ethernet_packet::get_packet() {
  unsigned char * newchar = new unsigned char[payload_size + 26];
  memcpy(newchar, packet, (unsigned int)(payload_size + 26));
  return newchar;
}

unsigned short ethernet_packet::get_packet_size() {
  return payload_size + 26;
}

void ethernet_packet::set_packet_size(unsigned char * newsize) {
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

unsigned short ethernet_packet::get_failed_size() {
  return failed_size;
}

void ethernet_packet::set_failed_size(unsigned short new_failed_size) {
  if (new_failed_size < 1526) {
    failed_size = 1526;
  } else {
    failed_size = new_failed_size;
  }
}

void ethernet_packet::calc_fcr() {
  // not implamentoed at this point
}

void ethernet_packet::print() {
  cout << "Packet Data:";
  for (unsigned int c = 0; c < get_packet_size(); c++) {
    cout << " 0x" << hex << (unsigned long)packet[c];
  }
  cout << endl;
}

ethernet_packet * ethernet_packet::clone() {
  ethernet_packet * newpacket = new ethernet_packet;
  memcpy(newpacket->packet, packet, 1526);
  newpacket->mac_destination = mac_destination;
  newpacket->mac_source = mac_source;
  newpacket->payload_size = payload_size;
  newpacket->time_stamp = time_stamp;
  calc_fcr();
  
  return newpacket;
}
