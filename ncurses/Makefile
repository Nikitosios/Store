CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncursesw
all: clean ncurses hello_world
ncurses:
	$(CC) $(CFLAGS) -o ncurses main.c $(LDFLAGS)
hello_world:
	$(CC) $(CFLAGS) -o hello_world hello_world.c $(LDFLAGS)
clean:
	rm -f ncurses hello_world
