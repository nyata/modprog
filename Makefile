# Makefile
# for compilie prog1 and prog2
# 4/12/2015 Nagisa YATA

CPP = g++
C = gcc
CFLAGS = -Wall
CPPOPT = -std=c++11 -pedantic

all: prog1 prog2 date square

%: %.c
	#$(C) $(CFLAGS) $< -o $@-gcc.o
	$(CXX) $(CPPOPT) $(CFLAGS) $< -o $@-g++.o

.PHONY: clean

clean:
	rm -f prog*.o
