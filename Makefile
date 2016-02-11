CC=g++
CFLAGS=-Wall -std=c++14
LDFLAGS=-lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi
SOURCES=$(wildcard src/*.cpp)

OBJECTS=$(addprefix obj/,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -rf obj/*
