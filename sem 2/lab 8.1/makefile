CC=g++
CFLAGS=-c -Wall -g -std=c++17
LDFLAGS=
SOURCES=LB8.1.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LB8.1.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@