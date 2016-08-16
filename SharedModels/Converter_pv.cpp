
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
//* This file contains the PV class for Converter.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 01:55:05 PM, (user: kenm)
//*>



#include "Converter_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
Converter_pv::Converter_pv(sc_module_name module_name) 
  : Converter_pv_base(module_name) {
}   

/////////////////////////////////////////////////////////////////////////////////
// Use these functions to define the behavior of your model when there is a 
// write event on one of the registers as defined in the Model Builder form.
// These functions are called before the write callbacks on the port.
///////////////////////////////////////////////////////////////////////////////// 

// Write callback for STAT_CFG_CNV register.
// The newValue has been already assigned to the STAT_CFG_CNV register.
void Converter_pv::cb_write_STAT_CFG_CNV(unsigned int newValue) {
  
}
    

// Read callback for Slave port.
// Returns true when successful.
bool Converter_pv::Slave_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

// Write callback for Slave port.
// Returns true when successful.
bool Converter_pv::Slave_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
} 




unsigned Converter_pv::Slave_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned Converter_pv::Slave_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool Converter_pv::Slave_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}

 
void Converter_pv::cb_transport_dbg_STAT_CFG_CNV(tlm::tlm_generic_payload& trans) {}

// callback for any change in signal: Convert of type: sc_in<bool>
void Converter_pv::Convert_callback() {

}

// in order to minimize merging conflicts, we recommend to add your functions after this comment
