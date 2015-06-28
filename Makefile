# Makefile for the raytracer

CC=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=raytracer

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
