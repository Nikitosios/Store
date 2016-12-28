CC=gcc
CFLAGS=-Wall
LDFLAGS=-lpthread
SOURCES=client.c server.c
EXE1=client
EXE2=server
all: $(SOURCES) $(EXE1) $(EXE2)
$(EXE1):
	$(CC) $(CFLAGS) -o $(EXE1) client.c
server:
	$(CC) $(CFLAGS) -o $(EXE2) server.c $(LDFLAGS)
clean:
	rm $(EXE1) $(EXE2)
