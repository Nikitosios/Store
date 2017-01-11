CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncursesw -lpanel
SOURCES=src/*
OBJECTS=build/*.o
EXE=$(shell basename `pwd`)
all: clean $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE) $(LDFLAGS)
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
	mkdir -p build/
	mv *.o build/
clean:
	rm -rf build/ $(EXE)
