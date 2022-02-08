CC = gcc
CFLAGS = -g -I .
all: chain

chain: simplechain.c 
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm chain