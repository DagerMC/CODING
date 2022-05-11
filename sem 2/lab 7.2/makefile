CC=g++
CFLAGS=-c -Wall -g -std=c++17
LDFLAGS=
SOURCES=LB7.cpp LB7Lib.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LB7

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@