CXX=g++ --std=c++14
CFLAGS=-c
LIB=-lpthread -ldl
INCLUDE=./sqlitelib

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.o : %.cpp
	$(CXX) $(CFLAGS) $?

%.out: %.o
	$(CXX) $< -o $@ $(INCLUDE)/sqlite3.o $(LIB)

#######all:	mybuild
clean :
	rm  *.out
