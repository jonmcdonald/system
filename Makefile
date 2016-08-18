TARGET_ARCH = linux

CC     = vista_c++
OPT    = 
DEBUG  = -DMB_DEBUG -tsv
OTHER  = +model_builder -sc23 -gcc47 -sc-dynamic -DSC_INCLUDE_DYNAMIC_PROCESSES 
OTHER  = +model_builder 
CFLAGS = $(DEBUG) $(OTHER)

MODELS  ?= models
EXE     ?= run.x
SC_MAIN ?= sc_main.cpp

VISTA_HOME = $(subst bin/vista,,$(shell which vista))
MODEL_BUILDER_HOME = $(VISTA_HOME)papoulis
VISTA_VERSION = $(strip $(patsubst Vista,,$(shell vista -version)))
MBCUSTOM = vista_work/papoulis_project$(VISTA_VERSION)/TLM/Generic_Library/Custom

SRCS = $(shell grep -L sc_main *.cpp)
SC_MAINS = $(shell grep -l sc_main *.cpp)
OBJS = $(SRCS:.cpp=.o)

MBFILES = $(wildcard */*.mb)
NUMMBFILES = $(words $(MBFILES))
MBDIRS = $(shell ls */*.mb | sed 's:/[^/]*$$::' | sort -u)
MBBLOCKSDIRS = $(shell ls -d */*.schematics | sed 's:/[^/]*schematics.*::' | sort -u)

PRJDIRS = $(shell ls *.v2p | sed 's:.v2p::')

MBSRCS = $(wildcard */*.cpp) 
MBOBJS = $(MBSRCS:.cpp=.o)
MBARCHIVE = lib$(MODELS).a

HDIR = $(shell ls */*.h | sed 's:/[^/]*$$::' | sort -u)
IDIR = $(foreach i,$(HDIR),-I$i)

INCDIR = -I. $(IDIR)

LIBS   = -L. -l$(MODELS)
DFILES = $(OBJS:.o=.d) $(MBOBJS:.o=.d)

S ?= sim
P ?= parameters.txt
T ?= traces.tcl
N ?= top

.SUFFIXES: .cpp .cc .o .x .h

$(EXE): vista.ini $(OBJS) $(MBARCHIVE) $(SC_MAIN)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ $(SC_MAIN) $(OBJS) $(LIBS) 2>&1 | c++filt

projects:
	for p in $(PRJDIRS); do vista_build_project $$p; done

vistagui: vista.ini $(EXE)

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
	rm -rf vista_work $(PRJDIRS) Object sim papoulis_project work
	find . -name "*~" -exec rm {} \;
	find . -name "*.d" -exec rm {} \;
	find . -name "*.gcno" -exec rm {} \;
	find . -name "*.gcda" -exec rm {} \;
	find . -name "*.gcov" -exec rm {} \;
	rm -rf app.info index* vista_* gcov* gmon* transcript *.png
	rm -f $(OBJS) $(MBOBJS) $(MBARCHIVE) $(EXE)

codeblocks: 
	codeblocks codeblocks.cbp 

vista: vista.ini $(EXE) $T
	vista -sc22 -trace-delta-cycles -tsv -memory-profiling \
		-event-debugging -with-cause -trace-all-sockets \
		-params $P -simdir $S -memory-profiling \
		-exec $(EXE) -simscript $T

batch: vista.ini $(EXE) $T
	vista -sc22 -tsv -simscript $T -params $P -simdir $S \
		-trace-all-sockets -batch -exec $(EXE)

run: $(EXE)
	./$(EXE)

events: $S
	vista_dump_events $S -kind initiator_socket -name $N > events2
	diff events*

$P:
	touch $P

$T:
	echo "#trace_transactions -name * -tree" > $T
	echo "#trace -name * -tree" >> $T
	echo "#trace -kind sc_object_attribute -name * -tree -unlimited" >> $T

COMMAND = "if {![does_tlm_library_exist $$mb]} \
	      {create_tlm_library $$mb $$mb}; \
	   reload_tlm_library $$mb;\
	   foreach n [glob -directory $$mb -tails *.mb] { \
	     puts \$$n; save_model -g TLM/$$mb/[lindex [split \$$n .] 0] }"

mb: vista.ini
	if [ $(NUMMBFILES) -gt "0" ]; then \
	  for mb in $(MBDIRS); do \
	    echo $(COMMAND); \
	    vista_model_builder -c $(COMMAND); \
	    done; \
	    fi;

vista.ini:
	echo "Creating vista.ini"
	@echo -n "ProjectsNamesMap {" > vista.ini
	@for p in $(PRJDIRS); do echo -n "$$p.v2p $$p " >> vista.ini; done
	@echo "}" >> vista.ini
	@echo -n "LibrariesMap {" >> vista.ini
	@for d in $(MBDIRS) $(MBBLOCKSDIRS); do echo -n "$$d $$d " >> vista.ini; done
	@echo "}" >> vista.ini
	

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

pa: $(EXE)
	vista_analysis sim

cov: $(EXE)
	lcov -d . -z
	vista_run run.x
	lcov -d . -c -o app.info
	genhtml app.info

define scmain
#include "systemc.h"
#include "top.h"

#define TOP top

using namespace std;
using namespace sc_core;

int sc_main(int argc, char *argv[]) {

  TOP *inst_top = new TOP("top");

  sc_start();

  delete inst_top;
  return 0;
}
endef

export scmain
$(SC_MAIN):
	echo "$$scmain" > $(SC_MAIN)

-include $(DFILES)
