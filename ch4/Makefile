CFLAGS=-Wall -Wpedantic -std=c89
ALL=calc ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08

.PHONY: all format clean install

all: $(ALL)

ex02: ex02.c
	$(CC) $(CFLAGS) $< -o $@ -lm

ex05: ex05.c
	$(CC) $(CFLAGS) $< -o $@ -lm

ex06: ex06.c
	$(CC) $(CFLAGS) $< -o $@ -lm

format:
	gindent *.c -kr -nut

clean:
	rm -f $(ALL) *.c~ *.core
