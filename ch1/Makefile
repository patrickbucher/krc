CFLAGS=-Wall -Wpedantic -std=c99
ALL=ex01 ex02 ex03

.PHONY: all format clean

all: $(ALL)

format:
	gindent -kr -nut *.c

clean:
	rm -f $(ALL) *.c~
