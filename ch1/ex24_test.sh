#!/usr/bin/env bash

set -euo pipefail

make ex24

# basic tests
echo '{[()]}' | ./ex24 || echo "err: single nested braces, brackets, parentheses"
echo '{{{[[[((()))]]]}}}' | ./ex24 || echo "err: triple nested braces, brackets, parentheses"
echo '"hello"' | ./ex24 || echo "err: double quotes"
echo '{ { { "{" } } }' | ./ex24 || echo "err: brace within double quotes"
echo '{ { { "'"{"'" } } }' | ./ex24 || echo "err: brace within single quotes"

# special cases (hard to write in shell code)
for f in ex24_test_*.txt
do
	./ex24 <$f || echo "err: ${f}"
done

# realistic tests using C source code
for c in *.c
do
	./ex24 <$c || echo "err: ${c}"
done
