#pragma once

#include "model_builder.h"

class ethernet_packet {
protected:
  unsigned char     packet[1526];
  unsigned long     mac_destination;
  unsigned long     mac_source;
  unsigned short    payload_size;
  unsigned short    failed_size;
public:
  enum              ethernet_status {normal, bussy, collision};
                    ethernet_packet();
                    ethernet_packet(unsigned char * newpacket, unsigned short size);
                    ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size);
                    ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size, unsigned short new_failed_size);
  void              clear();
  unsigned char *   get_preamble();
  unsigned char     get_start_of_frame_delimiter();
  unsigned long     get_mac_destination_as_long();
  unsigned char *   get_mac_destination_as_char();
  void              set_mac_destination(unsigned long Destination);
  void              set_mac_destination(unsigned char * Destination);
  unsigned long     get_mac_source_as_long();
  unsigned char *   get_mac_source_as_char();
  void              set_mac_source(unsigned long Source);
  void              set_mac_source(unsigned char * Source);
  unsigned char *   get_payload();
  void              set_payload(unsigned char * payload);
  void              set_payload_size(unsigned short newsize);
  unsigned short    get_payload_size();
  unsigned short    get_fcr();
  unsigned char *   get_packet();
  unsigned short    get_packet_size();
  void              set_packet_size(unsigned char * newsize);
  void              calc_fcr();
  unsigned short    get_failed_size();
  void              set_failed_size(unsigned short);
  ethernet_packet * clone();
  void              print();
  sc_time           time_stamp;
  ethernet_status      status;
};
