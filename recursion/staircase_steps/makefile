# compiler
CXX=g++
CXXFLAGS=-g -std=c++14  -Wall -Werror
BIN=staircaseStep

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
