CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncursesw -lpanel -lmenu -lform
SOURCES=src/*
OBJECTS=build/*.o
EXE=ncurses_chat
all: clean $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE) $(LDFLAGS)
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES) $(LDFLAGS)
	mkdir -p build/
	mv *.o build/
clean:
	rm -rf build/ $(EXE)
