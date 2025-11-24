CFLAGS=-Wall -Wpedantic -std=c99
ALL=ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 \
	ex11 ex12 ex13 ex14 ex15

.PHONY: all format clean

all: $(ALL)

format:
	gindent -kr -nut *.c

clean:
	rm -f $(ALL) *.c~
