SHELL   	= /bin/bash
CC      	= g++
CPPFLAGS	= -fPIC -pedantic -Wall -Wextra -march=native -ggdb3 -O3
TARGET 		= libProjectEuler.so
SOURCES		= $(wildcard src/*.cpp)
HEADERS		= $(wildcard src/*.h)
OBJECTS 	= $(SOURCES:.c=.o)
LDFLAGS     = -shared


all: $(TARGET)

$(TARGET):$(SOURCES)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(SOURCES):
	$(CC) $(CPPFLAGS) -c $@ 
