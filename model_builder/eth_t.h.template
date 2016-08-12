
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

#pragma once

#include "eth_model.h"

class eth_t: public eth_t_base {

public:
  eth_t(sc_core::sc_module_name module_name, long simulation,
                  esl::sc_sim::user_model::Arbiter* arbiter = 0)
    : eth_t_base(module_name, simulation, arbiter) {
    
  }

      /* policies callbacks */

  // The following callback is called for a target port. Note that the wait_states, power and 
  // influence_time are already computed using a learned policy (if any) or your defined
  // delay and/or power policy.
  // If under certain conditions you want to overwrite the above values, you have to overload
  // this callback in your derived class.
  
  virtual void evaluate_delay_policy(mb::mb_delay_request& request) {}
protected:

  // The following callback is called for an initiator port. Note that the latency, power and 
  // influence_time are already computed using a learned policy (if any) or your defined
  // split and/or power policy.
  // If under certain conditions you want to overwrite the above values, you have to overload
  // this callback in your derived class.

  virtual void evaluate_split_policy(mb::mb_split_request& request) {}

  /* called when "params.m_phase" is sent through the "port_index" port */
  virtual void sent_phase_cb(unsigned port_index,
                             esl::sc_sim::mb_cb_params& params) {}
                             
  /* called when "params.m_phase" is received by the "port_index" port */
  virtual void received_phase_cb(unsigned port_index,
                                 esl::sc_sim::mb_cb_params& params) {}
                             
  /* called when "params.m_phase" is sent through the "master_port_index".
     "params.m_t" is the time (in ps) between the current time
     and the time "params.m_phase" was received by the "slave_port_index */
  virtual void forward_arbitration_cb(unsigned master_port_index,
                                        unsigned slave_port_index,
                                      esl::sc_sim::mb_cb_params& params) {}
  /* called when "params.m_phase" is sent through the "slave_port_index".
     "params.m_t" is the time (in ps) between the current time
     and the time "params.m_phase" was received by the "master_port_index */
  virtual void backward_arbitration_cb(unsigned slave_port_index,
                                       unsigned master_port_index,
                                       esl::sc_sim::mb_cb_params& params) {}
  
  // The following function is called whenever a pipeline policy is detected on
  // the current initiator port transaction. If you want to overwrite the latency parameter, you
  // have to overload these functions in your derived class
  virtual void evaluate_pipeline_policy(mb::mb_request& cause_request, mb::mb_effect_request& effect_request) {}

  
  // The following callbacks are called whenever there is a transaction start or end in the port

  virtual void accept_generic_READ
    (long port_index,
     sc_dt::int64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 rDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}
  virtual void end_generic_READ
    (long port_index,
     sc_dt::uint64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 rDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}

  virtual void accept_generic_WRITE
    (long port_index,
     sc_dt::int64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 wDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}
  virtual void end_generic_WRITE
    (long port_index,
     sc_dt::uint64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 wDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}

};
