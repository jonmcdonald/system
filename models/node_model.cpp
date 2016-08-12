
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
//* The node_pv will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 03:01:29 PM, (user: jon)
//*>


#include "node_model.h"

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


node_pv_base::node_pv_base(sc_module_name& module_name) : 
  node_pv_base_mb_compatibility(module_name),
  node_pv_base_parameters(this),
  VISTA_MB_PV_INIT_MEMBER(y),
  VISTA_MB_PV_INIT_MEMBER(s) {
  

  // y - not a vector port
  // s - not a vector port
  unsigned u = 0;


  payload_on_stack = 0;
  payload_for_token = 0;
  reset_registers();
  
  // reset value for output signals

  // reset value for input signals

  // s bw binding 
  VISTA_MB_PV_BIND_FW_PROCESS_TO_TARGET(s);
  // y bw binding 
  VISTA_MB_PV_BIND_BW_PROCESS_TO_MASTER(y);
  // s bw callbacks 
  VISTA_MB_PV_REGISTER_SELF_FW_PROCESS_CALLBACKS(s);
  // y bw callbacks 
  VISTA_MB_PV_REGISTER_SELF_BW_PROCESS_CALLBACKS(y);

}

void node_pv_base::reset_registers() {
  // reset all registers
  unsigned u = 0;


}

void node_pv_base::reset_model() {
  
  reset_registers();
  // reset value for output signals

  // reset value for input signals

}

node_pv_base_parameters::node_pv_base_parameters(sc_object* object) :
  m_object(object),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, generic_clock, clock),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, mb_debug, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, call_to_default_if, false),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, verbose_parameters, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, dmi_enabled, true),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER_EXTERNALLY(object, s_pipeline_length, 2)
{
  if(verbose_parameters) print_parameters();
}

void node_pv_base_parameters::print_parameters()
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
  std::cout << "\tnominal_voltage = " << nominal_voltage << "\n";
  std::cout << "\tmb_debug = " << mb_debug << "\n";
  std::cout << "\tcall_to_default_if = " << call_to_default_if << "\n";
  std::cout << "\tverbose_parameters = " << verbose_parameters << "\n";
  std::cout << "\tdmi_enabled = " << dmi_enabled << "\n";
  std::cout << "\twarning_level = " << warning_level << "\n";
  std::cout << "\ts_pipeline_length = " << s_pipeline_length << "\n";
  std::cout.unsetf(ios::showbase);
  std::cout.setf(ios::dec, ios::basefield);
  std::cout << std::endl;
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
//* The node_t will be derived from this class.
//*
//* Model Builder version: 4.2.1
//* Generated on: Aug. 12, 2016 03:01:29 PM, (user: jon)
//*>




#include "node_model.h"
#include <math.h>
#include <stdlib.h>

using namespace esl::tlm_sim;
using namespace esl::sc_sim;
using namespace std;
using namespace sc_dt;
using namespace sc_core;


void node_t_base::schedule_generic_READ
(long port_index,
 sc_dt::uint64 delay,
 long& transactionSize,
 esl::include::transaction_power& power , long ADDR, long* rDATA, long PRIORITY, long BURST, long SIZE, long STATUS) {
  sc_dt::uint64 local_address = 0;
  local_address = ADDR,
  scheduleGenericTransaction(port_index,
                             0,
                             local_address,
                             (unsigned char*)rDATA,
                             transactionSize,
                             SIZE,
                             0, papoulis::getSimulationTime() + delay,
                             0,
                             0);
}

void node_t_base::schedule_generic_WRITE
(long port_index,
 sc_dt::uint64 delay,
 long& transactionSize,
 esl::include::transaction_power& power , long ADDR, long* wDATA, long PRIORITY, long BURST, long SIZE, long STATUS) {
  sc_dt::uint64 local_address = 0;
  local_address = ADDR,
  scheduleGenericTransaction(port_index,
                             1,
                             local_address,
                             (unsigned char*)wDATA,
                             transactionSize,
                             SIZE,
                             0, papoulis::getSimulationTime() + delay,
                             0,
                             0);
}



void node_t_base::start_transaction_generic_READ
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

void node_t_base::end_transaction_generic_READ
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
void node_t_base::start_transaction_generic_WRITE
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

void node_t_base::end_transaction_generic_WRITE
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

node_t_base::TransactionCallbackFunctionPointer node_t_base::getTransactionCallback(unsigned callbackIndex) {
  static TransactionCallbackFunctionPointer funcArray[] = {
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::start_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::start_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::start_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::start_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::end_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::end_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::end_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&node_t_base::end_transaction_generic_WRITE),
    0
  };
  if(callbackIndex >= sizeof(funcArray) / sizeof(*funcArray) - 1)
    return 0;
  return funcArray[callbackIndex];
}

config::real80 node_t_base::get_state_power() { 
  config::real80 power_value = 0;

  

  return power_value;
}

node_t_base::node_t_base(sc_module_name& module_name, long simulation) :
  papoulis::SystemCBaseModel(module_name),
  SD_INITIALIZE_PARAMETER(clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER(generic_clock, clock),
  SD_INITIALIZE_PARAMETER(nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER(mb_debug, false),
  SD_INITIALIZE_PARAMETER(call_to_default_if, false),
  SD_INITIALIZE_PARAMETER(verbose_parameters, true),
  SD_INITIALIZE_PARAMETER(dmi_enabled, true),
  SD_INITIALIZE_PARAMETER(warning_level, "WARNING"),
  SD_INITIALIZE_PARAMETER(s_pipeline_length, 2),
  m_simulation(simulation)
{
  bool separate_read_channel = false;  
  bool separate_write_channel = false;
  char* buffer = 0;
  unsigned port_index = 0;
  
  fix_clock_parameter(generic_clock, "generic_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[11];
    sprintf(buffer, "y");
    port_index = y;
    port_descriptions[port_index].port_name = buffer;
    port_descriptions[port_index].port_kind = PortDescription::READ_WRITE_CHANNEL_PORT;
    if (separate_write_channel && separate_read_channel)
      port_descriptions[port_index].port_kind = PortDescription::SEPARATE_READ_WRIE_CHANNEL_PORT;
    port_descriptions[port_index].is_read_write_address_channel = 0;
    
    port_descriptions[port_index].is_read_write_address_channel = 1;
    port_descriptions[port_index].is_master_port = 1;
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
    port_descriptions[port_index].port_must_bind = 0;
    port_descriptions[port_index].params_count = 6 + 10;
    port_descriptions[port_index].clock = generic_clock;
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !1, 1);
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !0, 1);
  
  
  fix_clock_parameter(generic_clock, "generic_clock");
    separate_read_channel = false;
    separate_write_channel = false;
    buffer = new char[11];
    sprintf(buffer, "s");
    port_index = s;
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
    port_descriptions[port_index].port_must_bind = 0;
    port_descriptions[port_index].params_count = 6 + 10;
    port_descriptions[port_index].clock = generic_clock;
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !0, 1);
    port_descriptions[port_index].add_read_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !1, 1);
  

  port_descriptions[y].default_read_transaction_name = "READ";
  
  port_descriptions[s].default_read_transaction_name = "READ";
  
  port_descriptions[y].default_write_transaction_name = "WRITE";
  
  port_descriptions[s].default_write_transaction_name = "WRITE";
  

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
  registerParameter("nominal_voltage", "double", sdGetParameterAsConstString("nominal_voltage"));
  registerParameter("mb_debug", "bool", sdGetParameterAsConstString("mb_debug"));
  registerParameter("call_to_default_if", "bool", sdGetParameterAsConstString("call_to_default_if"));
  registerParameter("verbose_parameters", "bool", sdGetParameterAsConstString("verbose_parameters"));
  registerParameter("dmi_enabled", "bool", sdGetParameterAsConstString("dmi_enabled"));
  registerParameter("warning_level", "const char*", sdGetParameterAsConstString("warning_level"));
  registerParameter("s_pipeline_length", "unsigned int", sdGetParameterAsConstString("s_pipeline_length"));
  set_sync_all(0); 
  
  
  
  
  

  
  

  


  

  constant_global_power_policy* p = new constant_global_power_policy(userRunningModel);
  
  
  
  set_global_power_policy(p);
}

void node_t_base::update_sync_all() {
  set_sync_all(0);
  
}

void node_t_base::update_pipeline_parameters(esl::sc_sim::pipeline_policy* handle) {
  if (m_pipeline_vector.size() == 0)
    return;


}

void node_t_base::update_sequential_parameters(esl::sc_sim::sequential_policy* handle) {
  if (m_sequential_vector.size() == 0)
    return;

}

void node_t_base::update_delay_parameters(esl::sc_sim::delay_policy* handle) {
  if (m_delay_vector.size() == 0)
    return;

}

void node_t_base::update_bus_parameters(esl::sc_sim::uniform_bus_policy* handle) {
  if (m_bus_vector.size() == 0)
    return;

}

void node_t_base::update_power_parameters(esl::sc_sim::power_policy* handle) {
  if (m_power_vector.size() == 0)
    return;

}

void node_t_base::update_state_power_parameters(esl::sc_sim::state_power_policy* handle) {
  if (m_state_power_vector.size() == 0)
    return;

}

void node_t_base::update_global_power_parameters(esl::sc_sim::constant_global_power_policy* handle) {
  
  
  return;  
}

bool node_t_base::triggerRegistersGotHit(unsigned portIndex, tlm::tlm_generic_payload& trans) {
  mb::utl::Segment<uint64_t> transactionRange(trans.get_address(), trans.get_address() + trans.get_data_length());

  return false;
}

bool node_t_base::portHasRegisters(unsigned portIndex) {
  switch (portIndex) {

  }
  return false;
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
//* This file contains the PVT class for node.
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
//* Generated on: Aug. 12, 2016 03:01:29 PM, (user: jon)
//*>

#include "node_model.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


#include "node_pv.h"




// Constructor

node_pvt::node_pvt(sc_module_name module_name)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
    node_pvt_param_defaults(this->name()),
    y("y"),
    s("s"),
    y_entry("unvisible_y_entry"),
    s_entry("unvisible_s_entry"),
    m_y_nb_connector(*this),
    m_s_nb_connector(*this)
    

{
  // y - not a vector port
  // s - not a vector port



  m_node_t = node_t_base::create_t("T", 1);
  m_node_pv = new node_pv("PV");
  bind();
}  


node_pvt::node_pvt(sc_module_name module_name, sc_core::sc_time clock_init, sc_core::sc_time generic_clock_init, double nominal_voltage_init, bool mb_debug_init, bool call_to_default_if_init, bool verbose_parameters_init, bool dmi_enabled_init, const char* warning_level_init, unsigned int s_pipeline_length_init)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  node_pvt_param_defaults(this->name(), clock_init, generic_clock_init, nominal_voltage_init, mb_debug_init, call_to_default_if_init, verbose_parameters_init, dmi_enabled_init, warning_level_init, s_pipeline_length_init),
    y("y"),
    s("s"),
    y_entry("unvisible_y_entry"),
    s_entry("unvisible_s_entry"),
    m_y_nb_connector(*this),
    m_s_nb_connector(*this)
    
{

  // y - not a vector port
  // s - not a vector port
  


  m_node_t = node_t_base::create_t("T", 1);
  m_node_pv = new node_pv("PV");
  bind();
} 

node_pvt::node_pvt(sc_module_name module_name,  std::vector<std::pair<char*, unsigned int> > &change_parameters)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
  node_pvt_param_defaults(this->name(), change_parameters),
    y("y"),
    s("s"),
    y_entry("unvisible_y_entry"),
    s_entry("unvisible_s_entry"),
    m_y_nb_connector(*this),
    m_s_nb_connector(*this)
    
{

  // y - not a vector port
  // s - not a vector port
  


  m_node_t = node_t_base::create_t("T", 1);
  m_node_pv = new node_pv("PV");
  bind();
} 

node_pvt::~node_pvt() {
  remove_pending_scenes();
  delete m_node_t; delete m_node_pv;
}




void node_pvt::bind()
{
  /* connect pv to entry ports */
  
  
  getPV()->y.bind(y_entry);
  s_entry.bind(getPV()->s);    

  /* set callbacks on external and entry ports */ 

  s.b_transport_cb.set(&s_entry, &s_entry_type::b_transport);
  s.transport_dbg_cb.set(&s_entry, &s_entry_type::transport_dbg);
  s.get_direct_mem_ptr_cb.set(&s_entry, &s_entry_type::get_direct_mem_ptr);
  
  y_entry.b_transport_cb.set(this, &self_type::b_transport_outside_y);
  y_entry.transport_dbg_cb.set(this, &self_type::transport_dbg_outside_y);
  y_entry.get_direct_mem_ptr_cb.set(&y, &y_type::get_direct_mem_ptr);
  
  
  /* connect t non blocking callbacks */

  y.nb_transport_bw_cb.set(this, &self_type::receive_nb_transport_y);
  getT()->set_port_cb(0, &m_y_nb_connector);
  
  s.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_s);
  getT()->set_port_cb(1, &m_s_nb_connector);
  
  s_entry.invalidate_direct_mem_ptr_cb.set(&s, &s_type::invalidate_direct_mem_ptr);

  y.invalidate_direct_mem_ptr_cb.set(&y_entry, &y_entry_type::invalidate_direct_mem_ptr);
  
  /* check mb_event policies */
  m_node_t->check_mb_events();
}



void node_pvt::b_transport_outside_y(tlm::tlm_generic_payload& p, sc_core::sc_time& t)
{
  if (!y.get_interface()) {
    p.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    std::stringstream buf;
    buf << "The port " << y.name() << " is unbound";
    mb::sysc::complain(buf.str().c_str(), y.name());
    return;
  }
  y.b_transport(p, t);
  
} 

unsigned int node_pvt::transport_dbg_outside_y(tlm::tlm_generic_payload& p)
{
  if (!y.get_interface()) {
     return 0;
  }
  return y.transport_dbg(p);
  
}

