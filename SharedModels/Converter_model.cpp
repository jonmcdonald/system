
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
//* The Converter_pv will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 01:55:05 PM, (user: kenm)
//*>


#include "Converter_model.h"

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


Converter_pv_base::Converter_pv_base(sc_module_name& module_name) : 
  Converter_pv_base_mb_compatibility(module_name),
  Converter_pv_base_parameters(this),
  VISTA_MB_PV_INIT_MEMBER(Slave),
  VISTA_MB_PV_INIT_MEMBER(Bone),
  VISTA_MB_PV_INIT_MEMBER(Convert),
  VISTA_MB_PV_INIT_MEMBER(Slave_memory),
  DATA("DATA", &Slave_memory, ((0x0000) / 4), ( (0) + (((0x0000) % 4) << 3)), ( (15) + (((0x0000) % 4) << 3)),  (32), mb::tlm20::READ_ACCESS),
  OFFSET("OFFSET", &Slave_memory, ((0x0004) / 4), ( (0) + (((0x0004) % 4) << 3)), ( (15) + (((0x0004) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCFG_CNVEN("STATCFG_CNVEN", &Slave_memory, ((0x0008) / 4), ( (0) + (((0x0008) % 4) << 3)), ( (0) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STATCFG_DONEN("STATCFG_DONEN", &Slave_memory, ((0x0008) / 4), ( (1) + (((0x0008) % 4) << 3)), ( (1) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  STAT_CFG_CNV("STAT_CFG_CNV", &Slave_memory, ((0x0008) / 4), ( (2) + (((0x0008) % 4) << 3)), ( (2) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_WRITE_ACCESS),
  CONVERTING("CONVERTING", &Slave_memory, ((0x0008) / 4), ( (3) + (((0x0008) % 4) << 3)), ( (3) + (((0x0008) % 4) << 3)),  (32), mb::tlm20::READ_ACCESS) {
  

  // Slave - not a vector port
  // Bone - not a vector port
  // Convert - not a vector port
  unsigned u = 0;


  Slave_memory.setPortIndex("Slave");
  payload_on_stack = 0;
  payload_for_token = 0;
  reset_registers();
  
  // reset value for output signals

  // Bone reset value not defined
  // reset value for input signals

  // Convert reset value not defined
  Convert.register_cb(this, &self::cb_signal_Convert);
  VISTA_MB_PV_SET_SELF_TRANSPORT_DBG(STAT_CFG_CNV);
  VISTA_MB_PV_SET_SELF_WRITE_CB(STAT_CFG_CNV);
  VISTA_MB_PV_SET_TARGET_GET_DMI_DELAY_CB(Slave);
  VISTA_MB_PV_BIND_FW_PROCESS_TO_MEMORY_DEFAULT_IF(Slave);
  // Slave bw callbacks 
  VISTA_MB_PV_REGISTER_SELF_FW_PROCESS_CALLBACKS(Slave);

}

void Converter_pv_base::reset_registers() {
  // reset all registers
  unsigned u = 0;


  DATA.setResetValue(0x00);
  OFFSET.setResetValue(0x00);
  STATCFG_CNVEN.setResetValue(0x0);
  STATCFG_DONEN.setResetValue(0x0);
  STAT_CFG_CNV.setResetValue(0x0);
  CONVERTING.setResetValue(0x0);
}

void Converter_pv_base::reset_model() {
  
  reset_registers();
  // reset value for output signals

  // Bone reset value not defined
  // reset value for input signals

  // Convert reset value not defined
}

Converter_pv_base_parameters::Converter_pv_base_parameters(sc_object* object) :
  m_object(object),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, generic_clock, clock),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, signal_clock, clock),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, mb_debug, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, call_to_default_if, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, verbose_parameters, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, dmi_enabled, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, Slave_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, Convert_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, convert_delay_in_clocks, 10)
{
  if(verbose_parameters) print_parameters();
}

void Converter_pv_base_parameters::print_parameters()
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
  std::cout << "\tgeneric_clock = " << generic_clock << "\n";
  std::cout << "\tsignal_clock = " << signal_clock << "\n";
  std::cout << "\tnominal_voltage = " << nominal_voltage << "\n";
  std::cout << "\tmb_debug = " << mb_debug << "\n";
  std::cout << "\tcall_to_default_if = " << call_to_default_if << "\n";
  std::cout << "\tverbose_parameters = " << verbose_parameters << "\n";
  std::cout << "\tdmi_enabled = " << dmi_enabled << "\n";
  std::cout << "\twarning_level = " << warning_level << "\n";
  std::cout << "\tSlave_pipeline_length = " << Slave_pipeline_length << "\n";
  std::cout << "\tConvert_pipeline_length = " << Convert_pipeline_length << "\n";
  std::cout << "\tconvert_delay_in_clocks = " << convert_delay_in_clocks << "\n";
  std::cout.unsetf(ios::showbase);
  std::cout.setf(ios::dec, ios::basefield);
  std::cout << std::endl;
}


void Converter_pv_base::end_of_elaboration() {
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
//* The Converter_t will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 01:55:05 PM, (user: kenm)
//*>




#include "Converter_model.h"
#include <math.h>
#include <stdlib.h>

using namespace esl::tlm_sim;
using namespace esl::sc_sim;
using namespace std;
using namespace sc_dt;
using namespace sc_core;


void Converter_t_base::schedule_signal_WRITE
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



void Converter_t_base::start_transaction_generic_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();
  
  
  this->accept_generic_READ
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3], 
     parameters[4], 
     parameters[5]);
}

void Converter_t_base::end_transaction_generic_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();                                                                         
  
  this->end_generic_READ
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3],
     parameters[4],
     parameters[5]);
}
void Converter_t_base::start_transaction_generic_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();
  
  
  this->accept_generic_WRITE
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3], 
     parameters[4], 
     parameters[5]);
}

void Converter_t_base::end_transaction_generic_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();                                                                         
  
  this->end_generic_WRITE
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3],
     parameters[4],
     parameters[5]);
}
void Converter_t_base::start_transaction_signal_WRITE
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

void Converter_t_base::end_transaction_signal_WRITE
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

Converter_t_base::TransactionCallbackFunctionPointer Converter_t_base::getTransactionCallback(unsigned callbackIndex) {
  static TransactionCallbackFunctionPointer funcArray[] = {
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::start_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::start_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::start_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::start_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::end_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::end_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::end_transaction_signal_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::null_transaction_callback),
    static_cast<TransactionCallbackFunctionPointer>(&Converter_t_base::end_transaction_signal_WRITE),
    0
  };
  if(callbackIndex >= sizeof(funcArray) / sizeof(*funcArray) - 1)
    return 0;
  return funcArray[callbackIndex];
}

config::real80 Converter_t_base::get_state_power() { 
  config::real80 power_value = 0;

  

  return power_value;
}

Converter_t_base::Converter_t_base(sc_module_name& module_name, long simulation) :
  papoulis::SystemCBaseModel(module_name),
  SD_INITIALIZE_PARAMETER(clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER(generic_clock, clock),
  SD_INITIALIZE_PARAMETER(signal_clock, clock),
  SD_INITIALIZE_PARAMETER(nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER(mb_debug, false),
  SD_INITIALIZE_PARAMETER(call_to_default_if, false),
  SD_INITIALIZE_PARAMETER(verbose_parameters, true),
  SD_INITIALIZE_PARAMETER(dmi_enabled, true),
  SD_INITIALIZE_PARAMETER(warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER(Slave_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER(Convert_pipeline_length, 2),
  SD_INITIALIZE_PARAMETER(convert_delay_in_clocks, 10),
  m_simulation(simulation),
  DATA("DATA", this),
  OFFSET("OFFSET", this),
  STATCFG_CNVEN("STATCFG_CNVEN", this),
  STATCFG_DONEN("STATCFG_DONEN", this),
  STAT_CFG_CNV("STAT_CFG_CNV", this),
  CONVERTING("CONVERTING", this)
{
  bool separate_read_channel = false;  
  bool separate_write_channel = false;
  char* buffer = 0;
  unsigned port_index = 0;
  
  fix_clock_parameter(generic_clock, "generic_clock");
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
    port_descriptions[port_index].protocol_name = "generic";
    port_descriptions[port_index].ipxactBusDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactBusDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactBusDef.name = "generic";
    port_descriptions[port_index].ipxactBusDef.version = "1.0"; 
    port_descriptions[port_index].ipxactAbstrDef.vendor = "Mentor.com";
    port_descriptions[port_index].ipxactAbstrDef.library = "Lib_ipxact";
    port_descriptions[port_index].ipxactAbstrDef.name = "generic_tlm20";
    port_descriptions[port_index].ipxactAbstrDef.version = "1.0";
    port_descriptions[port_index].port_must_bind = 1;
    port_descriptions[port_index].params_count = 6 + 10;
    port_descriptions[port_index].clock = generic_clock;
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !0, 1);
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !1, 1);
  
  
  fix_clock_parameter(signal_clock, "signal_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[17];
    sprintf(buffer, "Convert");
    port_index = Convert;
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
    buffer = new char[14];
    sprintf(buffer, "Bone");
    port_index = Bone;
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
  
  port_descriptions[Convert].default_write_transaction_name = "WRITE";
  
  port_descriptions[Bone].default_write_transaction_name = "WRITE";
  

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
  registerParameter("generic_clock", "sc_core::sc_time", sdGetParameterAsConstString("generic_clock"));
  registerParameter("signal_clock", "sc_core::sc_time", sdGetParameterAsConstString("signal_clock"));
  registerParameter("nominal_voltage", "double", sdGetParameterAsConstString("nominal_voltage"));
  registerParameter("mb_debug", "bool", sdGetParameterAsConstString("mb_debug"));
  registerParameter("call_to_default_if", "bool", sdGetParameterAsConstString("call_to_default_if"));
  registerParameter("verbose_parameters", "bool", sdGetParameterAsConstString("verbose_parameters"));
  registerParameter("dmi_enabled", "bool", sdGetParameterAsConstString("dmi_enabled"));
  registerParameter("warning_level", "const char*", sdGetParameterAsConstString("warning_level"));
  registerParameter("Slave_pipeline_length", "unsigned int", sdGetParameterAsConstString("Slave_pipeline_length"));
  registerParameter("Convert_pipeline_length", "unsigned int", sdGetParameterAsConstString("Convert_pipeline_length"));
  registerParameter("convert_delay_in_clocks", "unsigned int", sdGetParameterAsConstString("convert_delay_in_clocks"));
  set_sync_all(0); 
  
  
  
  
  

  
  

  


  

  constant_global_power_policy* p = new constant_global_power_policy(userRunningModel);
  
  
  
  set_global_power_policy(p);
}

void Converter_t_base::update_sync_all() {
  set_sync_all(0);
  
}

void Converter_t_base::update_pipeline_parameters(esl::sc_sim::pipeline_policy* handle) {
  if (m_pipeline_vector.size() == 0)
    return;


}

void Converter_t_base::update_sequential_parameters(esl::sc_sim::sequential_policy* handle) {
  if (m_sequential_vector.size() == 0)
    return;

}

void Converter_t_base::update_delay_parameters(esl::sc_sim::delay_policy* handle) {
  if (m_delay_vector.size() == 0)
    return;

}

void Converter_t_base::update_bus_parameters(esl::sc_sim::uniform_bus_policy* handle) {
  if (m_bus_vector.size() == 0)
    return;

}

void Converter_t_base::update_power_parameters(esl::sc_sim::power_policy* handle) {
  if (m_power_vector.size() == 0)
    return;

}

void Converter_t_base::update_state_power_parameters(esl::sc_sim::state_power_policy* handle) {
  if (m_state_power_vector.size() == 0)
    return;

}

void Converter_t_base::update_global_power_parameters(esl::sc_sim::constant_global_power_policy* handle) {
  
  
  return;  
}

bool Converter_t_base::triggerRegistersGotHit(unsigned portIndex, tlm::tlm_generic_payload& trans) {
  mb::utl::Segment<uint64_t> transactionRange(trans.get_address(), trans.get_address() + trans.get_data_length());

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

bool Converter_t_base::portHasRegisters(unsigned portIndex) {
  switch (portIndex) {

    {
    case 0:
      return true;
    }
  }
  return false;
}


unsigned Converter_t_base::getPortCountForRegister(unsigned regIndex) {
  if (!strcmp(get_register_name(regIndex), "DATA"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "OFFSET"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCFG_CNVEN"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STATCFG_DONEN"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "STAT_CFG_CNV"))
    return 1;
  if (!strcmp(get_register_name(regIndex), "CONVERTING"))
    return 1;
  return 0;
}

void Converter_t_base::getPortNamesForRegister(unsigned regIndex, const char **names) {
  long i = 0;
  if (!strcmp(get_register_name(regIndex), "DATA")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "OFFSET")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCFG_CNVEN")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STATCFG_DONEN")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "STAT_CFG_CNV")) {
    names[i++] = "Slave";
    return;
  }
  if (!strcmp(get_register_name(regIndex), "CONVERTING")) {
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
//* This file contains the PVT class for Converter.
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
//* Generated on: Aug. 12, 2016 01:55:05 PM, (user: kenm)
//*>

#include "Converter_model.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


#include "Converter_pv.h"




// Constructor

Converter_pvt::Converter_pvt(sc_module_name module_name)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
    Converter_pvt_param_defaults(this->name()),
    Slave("Slave"),
    Bone("Bone"),
    Convert("Convert"),
    Slave_entry("unvisible_Slave_entry"),
  Convert_entry("unvisible_Convert_entry"),
    m_Bone_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Convert_nb_connector(*this)
    

{
  // Slave - not a vector port

  // Bone - not a vector signal
  // Convert - not a vector signal


  m_Converter_t = Converter_t_base::create_t("T", 1);
  m_Converter_pv = new Converter_pv("PV");
  bind();
}  


Converter_pvt::Converter_pvt(sc_module_name module_name, sc_core::sc_time clock_init, sc_core::sc_time generic_clock_init, sc_core::sc_time signal_clock_init, double nominal_voltage_init, bool mb_debug_init, bool call_to_default_if_init, bool verbose_parameters_init, bool dmi_enabled_init, const char* warning_level_init, unsigned int Slave_pipeline_length_init, unsigned int Convert_pipeline_length_init, unsigned int convert_delay_in_clocks_init)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  Converter_pvt_param_defaults(this->name(), clock_init, generic_clock_init, signal_clock_init, nominal_voltage_init, mb_debug_init, call_to_default_if_init, verbose_parameters_init, dmi_enabled_init, warning_level_init, Slave_pipeline_length_init, Convert_pipeline_length_init, convert_delay_in_clocks_init),
    Slave("Slave"),
    Bone("Bone"),
    Convert("Convert"),
    Slave_entry("unvisible_Slave_entry"),
    Convert_entry("unvisible_Convert_entry"),
    m_Bone_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Convert_nb_connector(*this)
    
{

  // Slave - not a vector port
  // Bone - not a vector signal
  // Convert - not a vector signal
  


  m_Converter_t = Converter_t_base::create_t("T", 1);
  m_Converter_pv = new Converter_pv("PV");
  bind();
} 

Converter_pvt::Converter_pvt(sc_module_name module_name,  std::vector<std::pair<char*, unsigned int> > &change_parameters)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  Converter_pvt_param_defaults(this->name(), change_parameters),
    Slave("Slave"),
    Bone("Bone"),
    Convert("Convert"),
    Slave_entry("unvisible_Slave_entry"),
    Convert_entry("unvisible_Convert_entry"),
    m_Bone_nb_connector(*this),
    m_Slave_nb_connector(*this),
    m_Convert_nb_connector(*this)
    
{

  // Slave - not a vector port
  


  m_Converter_t = Converter_t_base::create_t("T", 1);
  m_Converter_pv = new Converter_pv("PV");
  bind();
} 

Converter_pvt::~Converter_pvt() {
  remove_pending_scenes();
  delete m_Converter_t; delete m_Converter_pv;
}




void Converter_pvt::bind()
{
  /* connect pv to entry ports */
  
  
  Slave_entry.bind(getPV()->Slave); 
  getPV()->Bone.bind(Bone_entry); 
  Convert_entry(getPV()->Convert);  

  /* set callbacks on external and entry ports */ 

  Slave.b_transport_cb.set(&Slave_entry, &Slave_entry_type::b_transport);
  Slave.transport_dbg_cb.set(&Slave_entry, &Slave_entry_type::transport_dbg);
  Slave.get_direct_mem_ptr_cb.set(&Slave_entry, &Slave_entry_type::get_direct_mem_ptr);
  
  Convert.b_transport_cb.set(this, &self_type::b_transport_inside_Convert);

  Bone_entry.write_cb.set(this, &self_type::b_transport_outside_Bone);
  

  
  /* connect t non blocking callbacks */

  Bone.nb_transport_bw_cb.set(this, &self_type::receive_nb_transport_Bone);
  getT()->set_port_cb(2, &m_Bone_nb_connector);
  
  Slave.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_Slave);
  getT()->set_port_cb(0, &m_Slave_nb_connector);
  
  Convert.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_Convert);
  getT()->set_port_cb(1, &m_Convert_nb_connector);
  
  Slave_entry.invalidate_direct_mem_ptr_cb.set(&Slave, &Slave_type::invalidate_direct_mem_ptr);

  /* check mb_event policies */
  m_Converter_t->check_mb_events();
}


void Converter_pvt::b_transport_inside_Convert(tlm::tlm_generic_payload& p, sc_core::sc_time& t)
{
  mb::tlm20::pvt_ext* extension = mb::tlm20::setup_pvt_ext(p);
  if (extension) {
    mb::mb_module* current_model = dynamic_cast<mb::mb_module*>(m_Converter_pv);
    if (current_model)
      current_model->set_current_token(extension->getToken());
  }
  Convert_entry.write(*(bool*)p.get_data_ptr());
}

void Converter_pvt::b_transport_outside_Bone(bool data)
{
  static tlm::tlm_generic_payload payload;

  payload.reset();
  payload.set_command(tlm::TLM_WRITE_COMMAND);
  payload.set_data_ptr((unsigned char*)&data);
  payload.set_data_length(sizeof(bool));
  payload.set_streaming_width(sizeof(bool));

  mb::tlm20::clear_pvt_ext(payload);
  mb::tlm20::setup_pvt_ext(payload)->set_signal(true);

  if (!Bone.get_interface()) {
    return;
  }

  mb::mb_module* current_model = dynamic_cast<mb::mb_module*>(m_Converter_pv);
  if (current_model)
    mb::tlm20::setup_pvt_ext(payload)->setToken(current_model->get_current_token());
  sc_time t;
  Bone.b_transport(payload, t);
}

