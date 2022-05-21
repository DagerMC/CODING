CC=g++
CFLAGS=-c -Wall -g -std=c++17
LDFLAGS=
SOURCES=LB8.2.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LB8.2.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@