#Makefile
#set up flags
CXX = g++
CXXFLAGS = -std=c++11
BOOST_LIB = -I /home/asalcedo/clibs/boost_1_66_0/
BOOST_FLAG = -g

all: solver

solver: solver.o
	${CXX} ${CXXFLAGS} ${BOOST_FLAG} ${BOOST_LIB} solver.o -o solver

solver.o: solver.cc
	${CXX} ${CXXFLAGS} ${BOOST_FLAG} ${BOOST_LIB} solver.cc -c -o solver.o

clean:
	rm -f solver  *.o *.out