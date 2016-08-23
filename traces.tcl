#trace_transactions -name * -tree
#trace -name * -tree
#trace -kind sc_object_attribute -name * -tree -unlimited
trace -kind sc_object_attribute -name DropSampleRate -tree -unlimited
trace -kind sc_object_attribute -name DropPacketRate -tree -unlimited
trace -kind sc_object_attribute -name RetryPacketRate -tree -unlimited
trace -kind sc_object_attribute -name m_num_readable -tree -unlimited
trace {(module)TopLevel1.(module)NODE0.(module)PV.(primchannel)SampleFifo.(base)tlm_fifo<_mgc_vista_model_builder_mb::fifo_elem<short unsigned int> >.(field)m_num_readable}
trace {(module)TopLevel1.(module)NODE1.(module)PV.(primchannel)SampleFifo.(base)tlm_fifo<_mgc_vista_model_builder_mb::fifo_elem<short unsigned int> >.(field)m_num_readable}
trace {(module)TopLevel1.(module)NODE2.(module)PV.(primchannel)SampleFifo.(base)tlm_fifo<_mgc_vista_model_builder_mb::fifo_elem<short unsigned int> >.(field)m_num_readable}
trace {(module)TopLevel1.(module)NODE3.(module)PV.(primchannel)SampleFifo.(base)tlm_fifo<_mgc_vista_model_builder_mb::fifo_elem<short unsigned int> >.(field)m_num_readable}
trace (module)TopLevel1.(module)SYSTEMCONTROLLER.(module)PV.(sc_object_attribute)Utilization
#trace {(module)TopLevel1.(module)SYSTEMCONTROLLER.(module)PV.(primchannel)ProcessFifo.(base)tlm_fifo<_mgc_vista_model_builder_mb::fifo_elem<ethernet_packet*> >.(field)m_num_readable}

