
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
//* This file contains the timing class for Converter.
//*
//* This is a template file: You may modify this file to implement the 
//* timing behavior of your component.
//* The functions below allows advance users to customize the timing behavior of your model.
//* 
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 01:55:05 PM, (user: kenm)
//*>


#include "Converter_t.h"


#include <iostream>

using namespace std;
using namespace sc_dt;
using namespace sc_core;

Converter_t_base* Converter_t_base::create_t(const char* name, long simulation) {
  return new Converter_t(name, simulation);
}

Converter_t::Converter_t(sc_module_name _name, long simulation)
  : Converter_t_base(_name, simulation) {
  
}

