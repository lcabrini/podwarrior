CC = gcc
CFLAGS = -g -Wall -O3 `curl-config --cflags` `xml2-config --cflags`
LDLIBS = `curl-config --libs` `xml2-config --libs`
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
PROG = podw

.PHONY: all
all: $(OBJ)
	gcc $(LDLIBS) -o $(PROG) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
