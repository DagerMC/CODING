CC=g++
CFLAGS=-c -Wall -g -std=c++17
LDFLAGS=
SOURCES=LB6.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LB6

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@