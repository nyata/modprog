## Makefile
## author:  Holger Arndt
## version: 26.07.2012

CPP = cpp
MAKEDEP = $(CPP) -MM
CXX = g++-4.7
CXXFLAGS = -Wall -std=c++11
#-fexceptions

CCSRC = glass.cc glasstst.cc
CCOBJ := $(patsubst %.cc,%.o,$(CCSRC))
CCDEP := $(patsubst %.cc,%.dep,$(CCSRC))

all: glasstst

glasstst: $(CCOBJ)
	$(CXX) $(INC) $(CCOBJ) -o $@

%.o: %.cc
	$(CXX) $(INC) $(CXXFLAGS) -c $<

%.dep: %.cc
	$(MAKEDEP) $< | sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@

clean:
	rm -f $(CCOBJ) $(CCDEP) glasstst

-include $(CCDEP)
