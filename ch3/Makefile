CFLAGS=-Wall -Wpedantic -std=c89
ALL=ex01 ex02 ex03 ex04 ex05 ex06

.PHONY: all format clean install

all: $(ALL)

format:
	gindent *.c -kr -nut

clean:
	rm -f $(ALL) *.c~ *.core
