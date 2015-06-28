# Makefile for the raytracer

CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=raytracer

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
