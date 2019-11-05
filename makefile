BUILD = $(shell date +"%Y%m%d_%H%M%S")
LDLIBS = Wl,--defsym,BUILD_$(BUILD)=0
BUILD_NUMBER_FILE=build-number.txt

# Include our auto incrementer
include Makefile.buildver

CXX=g++ --std=c++14
CFLAGS=-c
LIB=-lpthread -ldl
INCLUDE=./sqlitelib

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.o : %.cpp
	$(CXX) $(CFLAGS) $?

%.out: %.o
	$(CXX) $< -o $@ $(INCLUDE)/sqlite3.o $(LIB) $(LDFLAGS)  $(call buildver)

#######all:	mybuild
clean :
	rm  *.out
