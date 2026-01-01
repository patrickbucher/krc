CFLAGS=-Wall -Wpedantic -std=c89
ALL=ex01

.PHONY: all format clean install

all: $(ALL)

format:
	gindent *.c -kr -nut

clean:
	rm -f $(ALL) *.c~ *.core
