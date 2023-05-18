CC = g++
CFLAGS = -g -include bits/stdc++.h -std=c++17 -Wall -fdiagnostics-color=always

# Name of the executable
EXECUTABLE = main

# Source file (assumed to have the same name as the executable)
SOURCE = $(EXECUTABLE).cpp

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) -o bin/$(EXECUTABLE) $(SOURCE)

run: $(EXECUTABLE)
	./bin/$(EXECUTABLE)

clean:
	rm -f bin/$(EXECUTABLE)

build-run-clean: all run clean

