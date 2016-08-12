
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
//* This file contains the PV class for WaveSampleGenerator.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 06:35:19 AM, (user: kenm)
//* Automatically merged on: Aug. 12, 2016 09:06:39 AM, (user: kenm)
//* Automatically merged on: Aug. 12, 2016 09:08:12 AM, (user: kenm)
//*>


#pragma once

#include "WaveSampleGenerator_model.h"

using namespace tlm;

//This class inherits from the WaveSampleGenerator_pv_base class
class WaveSampleGenerator_pv : public WaveSampleGenerator_pv_base {
 public:
  typedef esl::tlm_types::Address mb_address_type;
 public:
  // Constructor
  // Do not add parameters here.
  // To add parameters - use the Model Builder form (under PV->Parameters tab)
  SC_HAS_PROCESS(WaveSampleGenerator_pv);
  WaveSampleGenerator_pv(sc_core::sc_module_name module_name);    

 protected:
  ////////////////////////////////////////
  // target ports read callbacks
  //////////////////////////////////////// 
  bool Slave_callback_read(mb_address_type address, unsigned char* data, unsigned size);
  
  unsigned Slave_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size); 

 protected:
  ////////////////////////////////////////
  // target ports write callbacks
  //////////////////////////////////////// 
  bool Slave_callback_write(mb_address_type address, unsigned char* data, unsigned size);
  
  unsigned Slave_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size);  
  bool Slave_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData);   
};

