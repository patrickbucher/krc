CFLAGS=-Wall -Wpedantic -std=c89
ALL=bin2dec dec2bin ex01 ex02 ex03 ex04 ex05 ex06

.PHONY: all format clean

all: $(ALL)

dec2bin: dec2bin.c
	$(CC) $(CFLAGS) $< -o $@ -lm

format:
	gindent *.c -kr -nut

clean:
	rm -f $(ALL) *.c~ *.core
