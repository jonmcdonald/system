#pragma once

#include "model_builder.h"

class ethernet_packet {
protected:
  unsigned char     packet[1526];    // used too hold the actual packet in a unsigned char array. max size is 1526 bytes
  unsigned long     mac_destination; // Destination MAC address in unsigned long
  unsigned long     mac_source;      // Destination MAC address in unsigned long
  unsigned short    payload_size;    // holds the size of the data contained in the packet. Maximium of 1500 bytes
public:
  ethernet_packet(); // Default constructor
  ethernet_packet(unsigned char * newpacket, unsigned short size); // Constructor from an unsigned char array 
  ethernet_packet(unsigned long destination, unsigned long source, unsigned char * new_payload, unsigned short new_payload_size); // Contructor based of MAC addrsses
  void              Clear();                                        // set all values to defualts and an empty payload
  unsigned char *   getPreamble();                                  // Gets to the Preamble "0x55 0x55 0x55 0x55 0x55 0x55 0x55"
  unsigned char     getDelimiter();                                 // Gets the ethernet delimiter "0xD5"
  unsigned long     getMacDestination();                            // returns the packets desination MAC address as an unsigned long
  void              setMacDestination(unsigned long Destination);   // sets the packets desination MAC address from an unsigned long
  void              setMacDestination(unsigned char * Destination); // sets the packets desination MAC address from an unsigned char array (size: 2 Bytes Big endian)
  unsigned long     getMacSource();                                 // returns the packets source MAC address as an unsigned long
  void              setMacSource(unsigned long Source);             // sets the packets source MAC address from an unsigned long
  void              setMacSource(unsigned char * Source);           // sets the packets source MAC address from an unsigned char array (size: 2 Bytes Big endian)
  unsigned char *   getPayload();                                   // Gets the data payload (only) portion of the ethernet packet
  void              setPayload(unsigned char * payload);            // Sets the data payload (only) portion of the ethernet packet based on setPayloadSize()
  void              setPayloadSize(unsigned short newsize);         // Sets the data payload (only) size in bytes (Packet size will be Payload Size + 26)
  unsigned short    getPayloadSize();                               // Gets the data payload (only) size in bytes (Packet size will be Payload Size + 26)
  unsigned short    getFcr();                                       // Gets the Error Correct and Detection Value
  void              calcFcr();                                      // Calulate Error Correct and Detection Value
  unsigned char *   getPacket();                                    // Returns a new unsigned char arrray containing the complete packet
  unsigned short    getPacketSize();                                // Get the size of the total packet in bytes (Payload Size + 26)
  void              setPacketSize(unsigned char * newsize);         // sets the packet size from unsigned char (size: 2 Bytes Big endian)
  ethernet_packet * Clone();                                        // Creats a NEW ethernet packet object instance based on the current object instance
  void              Print();                                        // sends information to standard out based on the currect object instance
  sc_time           TimeStamp;                                      // A variable for storing a SystemC time value
};
