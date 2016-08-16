
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


/* Generated by Model Builder  */

#pragma once
#ifndef __generic_h__
#define __generic_h__

#include "model_builder.h"
class generic_blocking_if : public virtual sc_core::sc_interface
{
public:
  virtual void WRITE(sc_dt::uint64 delay, long ADDR, const long* wDATA, long& burstSize, long PRIORITY, long BURST, long SIZE, long STATUS) = 0;
  virtual void READ(sc_dt::uint64 delay, long ADDR, long* rDATA, long& burstSize, long PRIORITY, long BURST, long SIZE, long STATUS) = 0;
  virtual sc_dt::uint64 getClock() = 0;
};

class generic_non_blocking_if : public virtual sc_core::sc_interface
{
public:
  virtual void nb_WRITE(sc_dt::uint64 delay, long ADDR, const long* wDATA, long& burstSize, long PRIORITY, long BURST, long SIZE, long STATUS) = 0;
  virtual void nb_READ(sc_dt::uint64 delay, long ADDR, long* rDATA, long& burstSize, long PRIORITY, long BURST, long SIZE, long STATUS) = 0;
  virtual const PapoulisEvent& endTransaction() = 0;
  virtual const PapoulisEvent& endAllTransactions() = 0;
  virtual bool canInitiateTransaction() = 0;
  virtual sc_dt::uint64 getClock() = 0;
};

#endif
