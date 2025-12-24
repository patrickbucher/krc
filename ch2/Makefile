CFLAGS=-Wall -Wpedantic -std=c89
ALL=ex01 ex02 ex03

.PHONY: all format clean

all: $(ALL)

format:
	gindent *.c -kr -nut

clean:
	rm -f $(ALL) *.c~ *.core
