TARGET_ARCH = linux

CC     = vista_c++
OPT    = 
DEBUG  = -DMB_DEBUG -tsv
OTHER  = +model_builder -sc23 -gcc47 -sc-dynamic -DSC_INCLUDE_DYNAMIC_PROCESSES 
OTHER  = +model_builder 
CFLAGS = $(DEBUG) $(OTHER)

MODELS = models
LOCAL  = schematics
MODULE = run
Project = Project

VISTA_HOME = $(subst bin/vista,,$(shell which vista))
MODEL_BUILDER_HOME = $(VISTA_HOME)papoulis
VISTA_VERSION = $(strip $(patsubst Vista,,$(shell vista -version)))
MBCUSTOM = vista_work/papoulis_project$(VISTA_VERSION)/TLM/Generic_Library/Custom

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

MBSRCS = $(wildcard $(MODELS)/[en]*.cpp)
MBOBJS = $(MBSRCS:.cpp=.o)
MBARCHIVE = lib$(MODELS).a

INCDIR = -I. -I$(LOCAL) -I$(MODELS)

LIBS   = -L. -l$(MODELS)
EXE    = $(MODULE).x
DFILES = $(OBJS:.o=.d) $(MBOBJS:.o=.d)

S ?= sim
P ?= parameters.txt
T ?= traces.tcl
N ?= top

.SUFFIXES: .cpp .cc .o .x .h

$(EXE): $(OBJS) $(MBARCHIVE)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ $(OBJS) $(MBOBJS) $(XL_UVMC) 2>&1 | c++filt
#	$(CC) $(CFLAGS) $(INCDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt
#	if [ ! -n "$$V2_HOME" ] ; \
#	then vista_build_project $(Project); fi

vistagui: $(EXE)

$(MBARCHIVE): $(MBOBJS)
	ar rcs $@ $(MBOBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $*.o
	@$(CC) -MM $(CFLAGS) $(INCDIR) -c $< > $*.d
	@sed -e 's|.*:|$*.o:|' < $*.d > $*.d.tmp
	@mv $*.d.tmp $*.d

.cc.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $*.o
	@$(CC) -MM $(CFLAGS) $(INCDIR) -c $< > $*.d
	@sed -e 's|.*:|$*.o:|' < $*.d > $*.d.tmp
	@mv $*.d.tmp $*.d

clean:
	rm -rf vista_work Project Source Object sim papoulis_project work
	find . -name "*~" -exec rm {} \;
	find . -name "*.d" -exec rm {} \;
	find . -name "*.gcno" -exec rm {} \;
	find . -name "*.gcda" -exec rm {} \;
	find . -name "*.gcov" -exec rm {} \;
	rm -rf app.info index* vista_* gcov* gmon* transcript *.png
	rm -f $(OBJS) $(MBOBJS) $(MBARCHIVE) $(EXE)

codeblocks: 
	codeblocks codeblocks.cbp 

vista: $(EXE) $T
	vista -sc22 -trace-delta-cycles -tsv -memory-profiling \
		-event-debugging -with-cause -trace-all-sockets \
		-params $P -simdir $S -memory-profiling \
		-exec $(EXE) -simscript $T

batch: $(EXE) $T
	vista -sc22 -tsv -simscript $T -params $P -simdir $S \
		-trace-all-sockets -batch -exec $(EXE)
#		-batch -exec $(EXE)

run: $(EXE)
	./$(EXE)

events: $S
	vista_dump_events $S -kind initiator_socket -name $N > events2
	diff events*

$T:
	echo "#trace_transactions -name * -tree" > $T
	echo "#trace -name * -tree" >> $T
	echo "#trace -kind sc_object_attribute -name * -tree -unlimited" >> $T

#COMMAND = "declare_communication_channel_type -t mb_fifo mb_fifo.h -operation_names {
#	     get nb_get nb_can_get peek nb_peek nb_can_peek put nb_put nb_can_put}; \

COMMAND = "if {![does_tlm_library_exist $(MODELS)]} \
	      {create_tlm_library $(MODELS) $(MODELS)}; \
	   reload_tlm_library $(MODELS);\
	   foreach n [glob -directory $(MODELS) -tails *.mb] { \
	     puts \$$n; save_model -g TLM/$(MODELS)/[lindex [split \$$n .] 0] }"

mb: 
	if [ -e $(MODELS) ]; then vista_model_builder -c $(COMMAND); fi

TemplatesCOMMAND = \
	"if {[ file exist protocols ]} \
	     {foreach p [glob -directory protocols -tails *.v] { \
	        parse_protocol_source protocols/\$$p } }; \
	 if {[ file exist templates ]} \
	   {foreach t [glob -directory templates -tails *] { \
             add_template \"/TLM/Generic_Library/Custom/\$$t\" [file join [pwd] \"templates/\$$t\"]; \
         }} "

$(MBCUSTOM): templates
	if [ -e templates ]; then \
	   vista_model_builder -c $(TemplatesCOMMAND); fi

papoulis_project:
	if [ -e $(HOME)/include/custom_models.tcl ]; then \
		vista_mb -c "source $(HOME)/include/custom_models.tcl"; fi
	@if [ -e $(MODELS) ]; then vista_model_builder -c $(COMMAND); fi

pa: $(EXE)
	vista_analysis sim

cov: $(EXE)
	lcov -d . -z
	vista_run run.x
	lcov -d . -c -o app.info
	genhtml app.info

-include $(DFILES)
