# compiler
CXX=clang++
CXXFLAGS=-g -std=c++11 -stdlib=libc++ -Wall -Werror
BIN=sort_anagrams

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
