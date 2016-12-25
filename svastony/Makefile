CC=gcc
CFLAGS=-Wall
PACKAGES=`pkg-config --cflags --libs gtk+-3.0`
LIBS=`pkg-config --libs gtk+-3.0`
EXE=svastony
all:
	$(CC) $(CFLAGS) -o $(EXE) main.c $(PACKAGES)
