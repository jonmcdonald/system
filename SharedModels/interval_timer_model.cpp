
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
//* This file is write protected. 
//* DO NOT MODIFY THIS FILE.
//*
//* This file is generated according to the parameters in the 
//* Model Builder form.
//* This class contains the infrastructure to define the behavior of the component.
//* The interval_timer_pv will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 04:43:09 PM, (user: kenm)
//*>


#include "interval_timer_model.h"

#ifdef MODEL_BUILDER_VERSION_NUMBER
#if 4201 != MODEL_BUILDER_VERSION_NUMBER
#error "This model was generated using Model Builder version: 4.2.1. Please regenerate model."
#endif
#else
#error "Please regenerate model."
#endif

using namespace sc_core;
using namespace sc_dt;
using namespace std;


interval_timer_pv_base::interval_timer_pv_base(sc_module_name& module_name) : 
  interval_timer_pv_base_mb_compatibility(module_name),
  interval_timer_pv_base_parameters(this),
  VISTA_MB_PV_INIT_MEMBER(Slave),
  VISTA_MB_PV_INIT_MEMBER(Interval),
  VISTA_MB_PV_INIT_MEMBER(Reset),
  VISTA_MB_PV_INIT_MEMBER(Slave_memory),
  CURRENTCOUNT("CURRENTCOUNT", &Slave_memory, ((0x0000) / 4), ( (0) + (((0x0000) % 4) << 3)), ( (31) + (((0x0000) % 4) << 3)),  (32), mb::tlm20::READ_ACCESS),
  INTERVALCOUNT("INTERVALCOUNT", &Slave_memory, ((0x0004) / 4), ( (0) + (((0x0004) % 4) << 3)), ( (31) + (((0x0004) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCTRL__ENOUT("STATCTRL__ENOUT", &Slave_memory, ((0x0008) / 4), ( (0) + (((0x0008) % 4) << 3)), ( (0) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCTRL__ENCNTINU("STATCTRL__ENCNTINU", &Slave_memory, ((0x0008) / 4), ( (1) + (((0x0008) % 4) << 3)), ( (1) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCTRL__ENCOUNT("STATCTRL__ENCOUNT", &Slave_memory, ((0x0008) / 4), ( (2) + (((0x0008) % 4) << 3)), ( (2) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCTRL__RUNNING("STATCTRL__RUNNING", &Slave_memory, ((0x0008) / 4), ( (3) + (((0x0008) % 4) << 3)), ( (3) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_ACCESS) {
  

  // Slave - not a vector port
  // Interval - not a vector port
  // Reset - not a vector port
  unsigned u = 0;


  Slave_memory.setPortIndex("Slave");
  payload_on_stack = 0;
  payload_for_token = 0;
  reset_registers();
  
  // reset value for output signals

  // Interval reset value not defined
  // reset value for input signals

  // Reset reset value not defined
  Reset.register_cb(this, &self::cb_signal_Reset);
  VISTA_MB_PV_SET_SELF_TRANSPORT_DBG(CURRENTCOUNT);
  VISTA_MB_PV_SET_SELF_TRANSPORT_DBG(STATCTRL__ENCOUNT);
  VISTA_MB_PV_SET_SELF_WRITE_CB(STATCTRL__ENCOUNT);
  VISTA_MB_PV_SET_SELF_READ_CB(CURRENTCOUNT);
  VISTA_MB_PV_SET_TARGET_GET_DMI_DELAY_CB(Slave);
  VISTA_MB_PV_BIND_FW_PROCESS_TO_MEMORY_DEFAULT_IF(Slave);
  // Slave bw callbacks 
  VISTA_MB_PV_REGISTER_SELF_FW_PROCESS_CALLBACKS(Slave);

}

void interval_timer_pv_base::reset_registers() {
  // reset all registers
  unsigned u = 0;


  CURRENTCOUNT.setResetValue(0x0);
  INTERVALCOUNT.setResetValue(0x0);
  STATCTRL__ENOUT.setResetValue(0x0);
  STATCTRL__ENCNTINU.setResetValue(0x0);
  STATCTRL__ENCOUNT.setResetValue(0x0);
  STATCTRL__RUNNING.setResetValue(0x0);
}

void interval_timer_pv_base::reset_model() {
  
  reset_registers();
  // reset value for output signals

  // Interval reset value not defined
  // reset value for input signals

  // Reset reset value not defined
}

interval_timer_pv_base_parameters::interval_timer_pv_base_parameters(sc_object* object) :
  m_object(object),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, ahb_slave_clock, clock),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, signal_clock, clock),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, mb_debug, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, call_to_default_if, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, verbose_parameters, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, dmi_enabled, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, Slave_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, Reset_pipeline_length, 2)
{
  if(verbose_parameters) print_parameters();
}

void interval_timer_pv_base_parameters::print_parameters()
{
  const char* name;
  if (!strcmp(m_object->basename(), "PV"))
    name = m_object->get_parent()->name();
  else
    name = m_object->name();

  std::cout.setf(ios::hex, ios::basefield);
  std::cout.setf(ios::showbase);
  std::cout << name << "::parameters:\n";
  std::cout << "\tclock = " << clock << "\n";
  std::cout << "\tahb_slave_clock = " << ahb_slave_clock << "\n";
  std::cout << "\tsignal_clock = " << signal_clock << "\n";
  std::cout << "\tnominal_voltage = " << nominal_voltage << "\n";
  std::cout << "\tmb_debug = " << mb_debug << "\n";
  std::cout << "\tcall_to_default_if = " << call_to_default_if << "\n";
  std::cout << "\tverbose_parameters = " << verbose_parameters << "\n";
  std::cout << "\tdmi_enabled = " << dmi_enabled << "\n";
  std::cout << "\twarning_level = " << warning_level << "\n";
  std::cout << "\tSlave_pipeline_length = " << Slave_pipeline_length << "\n";
  std::cout << "\tReset_pipeline_length = " << Reset_pipeline_length << "\n";
  std::cout.unsetf(ios::showbase);
  std::cout.setf(ios::dec, ios::basefield);
  std::cout << std::endl;
}


void interval_timer_pv_base::end_of_elaboration() {
  BASE_TYPE::end_of_elaboration();
  Slave_memory.bind_bw_direct_mem_if(Slave[0]);
}


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
//* This file is write protected. 
//* DO NOT MODIFY THIS FILE.
//*
//* This file is generated according to the parameters in the 
//* Model Builder form.
//* 
//* Any change in parameters, policies, ports, protocols, etc. will change this file
//* upon generation of the timing model (using generate_timing_model command).
//* The interval_timer_t will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 04:43:10 PM, (user: kenm)
//*>




#include "interval_timer_model.h"
#include <math.h>
#include <stdlib.h>

using namespace esl::tlm_sim;
using namespace esl::sc_sim;
using namespace std;
using namespace sc_dt;
using namespace sc_core;


void interval_timer_t_base::schedule_signal_WRITE
(long port_index,
 sc_dt::uint64 delay,
 long& transactionSize,
 esl::include::transaction_power& power , long address, long* value_p, long block_size) {
  sc_dt::uint64 local_address = 0;
  local_address = address,
  scheduleGenericTransaction(port_index,
                             1,
                             local_address,
                             (unsigned char*)value_p,
                             transactionSize,
                             block_size,
                             0, papoulis::getSimulationTime() + delay,
                             0,
                             0);
}



void interval_timer_t_base::start_transaction_ahb_slave_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();
  
  
  this->accept_ahb_slave_READ
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3]);
}

void interval_timer_t_base::end_transaction_ahb_slave_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();                                                                         
  
  this->end_ahb_slave_READ
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3]);
}
void interval_timer_t_base::start_transaction_ahb_slave_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();
  
  
  this->accept_ahb_slave_WRITE
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3]);
}

void interval_timer_t_base::end_transaction_ahb_slave_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();                                                                         
  
  this->end_ahb_slave_WRITE
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3]);
}
void interval_timer_t_base::start_transaction_signal_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();
  
  
  this->accept_signal_WRITE
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2]);
}

void interval_timer_t_base::end_transaction_signal_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[2] = request->getBlockSize();                                                                         
  
  this->end_signal_WRITE
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2]);
}

interval_timer_t_base::TransactionCallbackFunctionPointer interval_timer_t_base::getTransactionCallback(unsigned callbackIndex) {
  static TransactionCallbackFunctionPointer funcArray[] = {
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::start_transaction_ahb_slave_READ),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::start_transaction_ahb_slave_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::start_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::start_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::end_transaction_ahb_slave_READ),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::end_transaction_ahb_slave_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::end_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&interval_timer_t_base::end_transaction_signal_WRITE),
    0
  };
  if(callbackIndex >= sizeof(funcArray) / sizeof(*funcArray) - 1)
    return 0;
  return funcArray[callbackIndex];
}

config::real80 interval_timer_t_base::get_state_power() { 
  config::real80 power_value = 0;

  

  return power_value;
}

interval_timer_t_base::interval_timer_t_base(sc_module_name& module_name, long simulation) :
  papoulis::SystemCBaseModel(module_name),
  SD_INITIALIZE_PARAMETER(clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER(ahb_slave_clock, clock),
  SD_INITIALIZE_PARAMETER(signal_clock, clock),
  SD_INITIALIZE_PARAMETER(nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER(mb_debug, false),
  SD_INITIALIZE_PARAMETER(call_to_default_if, false),
  SD_INITIALIZE_PARAMETER(verbose_parameters, true),
  SD_INITIALIZE_PARAMETER(dmi_enabled, true),
  SD_INITIALIZE_PARAMETER(warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER(Slave_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER(Reset_pipeline_length, 2),
  m_simulation(simulation),
  CURRENTCOUNT("CURRENTCOUNT", this),
  INTERVALCOUNT("INTERVALCOUNT", this),
  STATCTRL__ENOUT("STATCTRL__ENOUT", this),
  STATCTRL__ENCNTINU("STATCTRL__ENCNTINU", this),
  STATCTRL__ENCOUNT("STATCTRL__ENCOUNT", this),
  STATCTRL__RUNNING("STATCTRL__RUNNING", this)
{
  bool separate_read_channel = false;  
  bool separate_write_channel = false;
  char* buffer = 0;
  unsigned port_index = 0;
  
  fix_clock_parameter(ahb_slave_clock, "ahb_slave_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[15];
    sprintf(buffer, "Slave");
    port_index = Slave;
    port_descriptions[port_index].port_name = buffer;
    port_descriptions[port_index].port_kind = PortDescription::READ_WRITE_CHANNEL_PORT;
    if (separate_write_channel && separate_read_channel)
      port_descriptions[port_index].port_kind = PortDescription::SEPARATE_READ_WRIE_CHANNEL_PORT;
    port_descriptions[port_index].is_read_write_address_channel = 0;
    
    port_descriptions[port_index].is_read_write_address_channel = 1;
    port_descriptions[port_index].is_master_port = 0;
    port_descriptions[port_index].is_signal_port = 0;
    port_descriptions[port_index].port_width = ((32 + 7) >> 3);
    port_descriptions[port_index].port_width_in_bits = 32;
    port_descriptions[port_index].protocol_name = "ahb_slave";
    port_descriptions[port_index].ipxactBusDef.vendor = "amba.com";
    port_descriptions[port_index].ipxactBusDef.library = "AMBA2";
    port_descriptions[port_index].ipxactBusDef.name = "AHB";
    port_descriptions[port_index].ipxactBusDef.version = "r2p0_6"; 
    port_descriptions[port_index].ipxactAbstrDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactAbstrDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactAbstrDef.name = "AHB_tlm20";
    port_descriptions[port_index].ipxactAbstrDef.version = "1.0";
    port_descriptions[port_index].port_must_bind = 1;
    port_descriptions[port_index].params_count = 4 + 10;
    port_descriptions[port_index].clock = ahb_slave_clock;
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !0, 1);
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !1, 1);
  
  
  fix_clock_parameter(signal_clock, "signal_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[15];
    sprintf(buffer, "Reset");
    port_index = Reset;
    port_descriptions[port_index].port_name = buffer;
    separate_write_channel = true;
    port_descriptions[port_index].port_kind = PortDescription::WRITE_CHANNEL_PORT;
    if (separate_write_channel && separate_read_channel)
      port_descriptions[port_index].port_kind = PortDescription::SEPARATE_READ_WRIE_CHANNEL_PORT;
    port_descriptions[port_index].is_read_write_address_channel = 0;
    
    port_descriptions[port_index].is_master_port = 0;
    port_descriptions[port_index].is_signal_port = 1;
    port_descriptions[port_index].port_width = ((1 + 7) >> 3);
    port_descriptions[port_index].port_width_in_bits = 1;
    port_descriptions[port_index].protocol_name = "signal";
    port_descriptions[port_index].ipxactBusDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactBusDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactBusDef.name = "signal";
    port_descriptions[port_index].ipxactBusDef.version = "1.0"; 
    port_descriptions[port_index].ipxactAbstrDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactAbstrDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactAbstrDef.name = "signal_tlm20";
    port_descriptions[port_index].ipxactAbstrDef.version = "1.0";
    port_descriptions[port_index].port_must_bind = 0;
    port_descriptions[port_index].params_count = 3 + 10;
    port_descriptions[port_index].clock = signal_clock;
    port_descriptions[port_index].add_write_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !0, 1);
    port_descriptions[port_index].add_write_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !1, 1);
  
  
  fix_clock_parameter(signal_clock, "signal_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[18];
    sprintf(buffer, "Interval");
    port_index = Interval;
    port_descriptions[port_index].port_name = buffer;
    separate_write_channel = true;
    port_descriptions[port_index].port_kind = PortDescription::WRITE_CHANNEL_PORT;
    if (separate_write_channel && separate_read_channel)
      port_descriptions[port_index].port_kind = PortDescription::SEPARATE_READ_WRIE_CHANNEL_PORT;
    port_descriptions[port_index].is_read_write_address_channel = 0;
    
    port_descriptions[port_index].is_master_port = 1;
    port_descriptions[port_index].is_signal_port = 1;
    port_descriptions[port_index].port_width = ((1 + 7) >> 3);
    port_descriptions[port_index].port_width_in_bits = 1;
    port_descriptions[port_index].protocol_name = "signal";
    port_descriptions[port_index].ipxactBusDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactBusDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactBusDef.name = "signal";
    port_descriptions[port_index].ipxactBusDef.version = "1.0"; 
    port_descriptions[port_index].ipxactAbstrDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactAbstrDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactAbstrDef.name = "signal_tlm20";
    port_descriptions[port_index].ipxactAbstrDef.version = "1.0";
    port_descriptions[port_index].port_must_bind = 0;
    port_descriptions[port_index].params_count = 3 + 10;
    port_descriptions[port_index].clock = signal_clock;
    port_descriptions[port_index].add_write_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !1, 1);
    port_descriptions[port_index].add_write_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !0, 1);
  

  port_descriptions[Slave].default_read_transaction_name = "READ";
  
  port_descriptions[Slave].default_write_transaction_name = "WRITE";
  
  port_descriptions[Reset].default_write_transaction_name = "WRITE";
  
  port_descriptions[Interval].default_write_transaction_name = "WRITE";
  

  fix_internal_clock_parameter(clock, "clock");
  set_ports(mb::sysc::sc_time_to_ps(clock), port_count, port_descriptions);

  bool isCpu = false;
  
  esl::tlm_sim::UserRunningModel* userRunningModel = Papoulis_CreateUserRunningModel(name(),
                                                                                     0,
                                                                                     this,
                                                                                     simulation,
                                                                                     false,
                                                                                     isCpu);
  setUserRunningModel(userRunningModel, isCpu);
  set_nominal_voltage(nominal_voltage);
  registerParameter("clock", "sc_core::sc_time", sdGetParameterAsConstString("clock"));
  registerParameter("ahb_slave_clock", "sc_core::sc_time", sdGetParameterAsConstString("ahb_slave_clock"));
  registerParameter("signal_clock", "sc_core::sc_time", sdGetParameterAsConstString("signal_clock"));
  registerParameter("nominal_voltage", "double", sdGetParameterAsConstString("nominal_voltage"));
  registerParameter("mb_debug", "bool", sdGetParameterAsConstString("mb_debug"));
  registerParameter("call_to_default_if", "bool", sdGetParameterAsConstString("call_to_default_if"));
  registerParameter("verbose_parameters", "bool", sdGetParameterAsConstString("verbose_parameters"));
  registerParameter("dmi_enabled", "bool", sdGetParameterAsConstString("dmi_enabled"));
  registerParameter("warning_level", "const char*", sdGetParameterAsConstString("warning_level"));
  registerParameter("Slave_pipeline_length", "unsigned int", sdGetParameterAsConstString("Slave_pipeline_length"));
  registerParameter("Reset_pipeline_length", "unsigned int", sdGetParameterAsConstString("Reset_pipeline_length"));
  set_sync_all(0); 
  
  
  
  
  

  
  

  


  

  constant_global_power_policy* p = new constant_global_power_policy(userRunningModel);
  
  
  
  set_global_power_policy(p);
}

void interval_timer_t_base::update_sync_all() {
  set_sync_all(0);
  
}

void interval_timer_t_base::update_pipeline_parameters(esl::sc_sim::pipeline_policy* handle) {
  if (m_pipeline_vector.size() == 0)
    return;


}

void interval_timer_t_base::update_sequential_parameters(esl::sc_sim::sequential_policy* handle) {
  if (m_sequential_vector.size() == 0)
    return;

}

void interval_timer_t_base::update_delay_parameters(esl::sc_sim::delay_policy* handle) {
  if (m_delay_vector.size() == 0)
    return;

}

void interval_timer_t_base::update_bus_parameters(esl::sc_sim::uniform_bus_policy* handle) {
  if (m_bus_vector.size() == 0)
    return;

}

void interval_timer_t_base::update_power_parameters(esl::sc_sim::power_policy* handle) {
  if (m_power_vector.size() == 0)
    return;

}

void interval_timer_t_base::update_state_power_parameters(esl::sc_sim::state_power_policy* handle) {
  if (m_state_power_vector.size() == 0)
    return;

}

void interval_timer_t_base::update_global_power_parameters(esl::sc_sim::constant_global_power_policy* handle) {
  
  
  return;  
}

bool interval_timer_t_base::triggerRegistersGotHit(unsigned portIndex, tlm::tlm_generic_payload& trans) {
  mb::utl::Segment<uint64_t> transactionRange(trans.get_address(), trans.get_address() + trans.get_data_length());

  {
    if (0 == portIndex) {
      mb::utl::Segment<uint64_t> current((1 + ((0x0000 % 4) << 3)), (1 + ((0x0000 % 4) << 3)));
      mb::utl::Segment<uint64_t> intersect = transactionRange.intersect(current);
      if (!intersect.empty())
        return true;
    }
  }
  {
    if (0 == portIndex) {
      mb::utl::Segment<uint64_t> current((1 + ((0x0008 % 4) << 3)), (1 + ((0x0008 % 4) << 3)));
      mb::utl::Segment<uint64_t> intersect = transactionRange.intersect(current);
      if (!intersect.empty())
        return true;
    }
  }
  return false;
}

bool interval_timer_t_base::portHasRegisters(unsigned portIndex) {
  switch (portIndex) {

    {
    case 0:
      return true;
    }
  }
  return false;
}


unsigned interval_timer_t_base::getPortCountForRegister(unsigned regIndex) {
  if (!strcmp(get_register_name(regIndex), "CURRENTCOUNT"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "INTERVALCOUNT"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENOUT"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENCNTINU"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENCOUNT"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCTRL__RUNNING"))
    return 1;
  return 0;
}

void interval_timer_t_base::getPortNamesForRegister(unsigned regIndex, const char **names) {
  long i = 0;
  if (!strcmp(get_register_name(regIndex), "CURRENTCOUNT")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "INTERVALCOUNT")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENOUT")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENCNTINU")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCTRL__ENCOUNT")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCTRL__RUNNING")) {
    names[i++] = "Slave";
    return;
  }
}


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
//* This file is write protected.
//* DO NOT MODIFY THIS FILE.
//*
//* This file contains the PVT class for interval_timer.
//* It connects between the PV and T models.
//* Your top-level design should instantiate this model.
//* 
//* In order to synchronize the activty between the PV and the T models, every 
//* PV transaction is monitored and queued in the T sync ports.
//* Whenever a synchronization point is reached, the T models are executed and 
//* the corresponding T transactions are launched.
//* A synchronization point is reached whenever there is a wait statement on a testbench thread. 
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 04:43:10 PM, (user: kenm)
//*>

#include "interval_timer_model.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


#include "interval_timer_pv.h"




// Constructor

interval_timer_pvt::interval_timer_pvt(sc_module_name module_name)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
    interval_timer_pvt_param_defaults(this->name()),
    Slave("Slave"),
    Interval("Interval"),
    Reset("Reset"),
    Slave_entry("unvisible_Slave_entry"),
  Reset_entry("unvisible_Reset_entry"),
    m_Interval_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Reset_nb_connector(*this)
    

{
  // Slave - not a vector port

  // Interval - not a vector signal
  // Reset - not a vector signal


  m_interval_timer_t = interval_timer_t_base::create_t("T", 1);
  m_interval_timer_pv = new interval_timer_pv("PV");
  bind();
}  


interval_timer_pvt::interval_timer_pvt(sc_module_name module_name, sc_core::sc_time clock_init, sc_core::sc_time ahb_slave_clock_init, sc_core::sc_time signal_clock_init, double nominal_voltage_init, bool mb_debug_init, bool call_to_default_if_init, bool verbose_parameters_init, bool dmi_enabled_init, const char* warning_level_init, unsigned int Slave_pipeline_length_init, unsigned int Reset_pipeline_length_init)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  interval_timer_pvt_param_defaults(this->name(), clock_init, ahb_slave_clock_init, signal_clock_init, nominal_voltage_init, mb_debug_init, call_to_default_if_init, verbose_parameters_init, dmi_enabled_init, warning_level_init, Slave_pipeline_length_init, Reset_pipeline_length_init),
    Slave("Slave"),
    Interval("Interval"),
    Reset("Reset"),
    Slave_entry("unvisible_Slave_entry"),
    Reset_entry("unvisible_Reset_entry"),
    m_Interval_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Reset_nb_connector(*this)
    
{

  // Slave - not a vector port
  // Interval - not a vector signal
  // Reset - not a vector signal
  


  m_interval_timer_t = interval_timer_t_base::create_t("T", 1);
  m_interval_timer_pv = new interval_timer_pv("PV");
  bind();
} 

interval_timer_pvt::interval_timer_pvt(sc_module_name module_name,  std::vector<std::pair<char*, unsigned int> > &change_parameters)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  interval_timer_pvt_param_defaults(this->name(), change_parameters),
    Slave("Slave"),
    Interval("Interval"),
    Reset("Reset"),
    Slave_entry("unvisible_Slave_entry"),
    Reset_entry("unvisible_Reset_entry"),
    m_Interval_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Reset_nb_connector(*this)
    
{

  // Slave - not a vector port
  


  m_interval_timer_t = interval_timer_t_base::create_t("T", 1);
  m_interval_timer_pv = new interval_timer_pv("PV");
  bind();
} 

interval_timer_pvt::~interval_timer_pvt() {
  remove_pending_scenes();
  delete m_interval_timer_t; delete m_interval_timer_pv;
}




void interval_timer_pvt::bind()
{
  /* connect pv to entry ports */
  
  
  Slave_entry.bind(getPV()->Slave); 
  getPV()->Interval.bind(Interval_entry); 
  Reset_entry(getPV()->Reset);  

  /* set callbacks on external and entry ports */ 

  Slave.b_transport_cb.set(&Slave_entry, &Slave_entry_type::b_transport);
  Slave.transport_dbg_cb.set(&Slave_entry, &Slave_entry_type::transport_dbg);
  Slave.get_direct_mem_ptr_cb.set(&Slave_entry, &Slave_entry_type::get_direct_mem_ptr);
  
  Reset.b_transport_cb.set(this, &self_type::b_transport_inside_Reset);

  Interval_entry.write_cb.set(this, &self_type::b_transport_outside_Interval);
  

  
  /* connect t non blocking callbacks */

  Interval.nb_transport_bw_cb.set(this, &self_type::receive_nb_transport_Interval);
  getT()->set_port_cb(2, &m_Interval_nb_connector);
  
  Slave.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_Slave);
  getT()->set_port_cb(0, &m_Slave_nb_connector);
  
  Reset.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_Reset);
  getT()->set_port_cb(1, &m_Reset_nb_connector);
  
  Slave_entry.invalidate_direct_mem_ptr_cb.set(&Slave, &Slave_type::invalidate_direct_mem_ptr);

  /* check mb_event policies */
  m_interval_timer_t->check_mb_events();
}


void interval_timer_pvt::b_transport_inside_Reset(tlm::tlm_generic_payload& p, sc_core::sc_time& t)
{
  mb::tlm20::pvt_ext* extension = mb::tlm20::setup_pvt_ext(p);
  if (extension) {
    mb::mb_module* current_model = dynamic_cast<mb::mb_module*>(m_interval_timer_pv);
    if (current_model)
      current_model->set_current_token(extension->getToken());
  }
  Reset_entry.write(*(bool*)p.get_data_ptr());
}

void interval_timer_pvt::b_transport_outside_Interval(bool data)
{
  static tlm::tlm_generic_payload payload;

  payload.reset();
  payload.set_command(tlm::TLM_WRITE_COMMAND);
  payload.set_data_ptr((unsigned char*)&data);
  payload.set_data_length(sizeof(bool));
  payload.set_streaming_width(sizeof(bool));

  mb::tlm20::clear_pvt_ext(payload);
  mb::tlm20::setup_pvt_ext(payload)->set_signal(true);

  if (!Interval.get_interface()) {
    return;
  }

  mb::mb_module* current_model = dynamic_cast<mb::mb_module*>(m_interval_timer_pv);
  if (current_model)
    mb::tlm20::setup_pvt_ext(payload)->setToken(current_model->get_current_token());
  sc_time t;
  Interval.b_transport(payload, t);
}
