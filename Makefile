# Makefile for the raytracer

CC=g++
CFLAGS=-c -Wall -std=c++11 -ggdb
LDFLAGS=

SRCEXT := cpp
SRC_DIR := src
BUILD_DIR := build
TARGET_DIR := bin
TARGET := $(TARGET_DIR)/raytracer

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRCEXT)=.o))

INC = -I include
EXECUTABLE=raytracer

RM := rm -r

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(TARGET_DIR)
	$(CC) $^ -o $(TARGET) 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) $(BUILD_DIR) $(TARGET_DIR)

again: clean all
