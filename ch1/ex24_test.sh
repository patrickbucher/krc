#!/usr/bin/env bash

set -euo pipefail

make ex24

echo '{[()]}' | ./ex24 || echo "err: single nested braces, brackets, parentheses"
echo '{{{[[[((()))]]]}}}' | ./ex24 || echo "err: triple nested braces, brackets, parentheses"
echo '"hello"' | ./ex24 || echo "err: double quotes"
echo '{ { { "{" } } }' | ./ex24 || echo "err: brace within double quotes"
echo '{ { { "'"{"'" } } }' | ./ex24 || echo "err: brace within single quotes"
for f in ex24_test_*.txt
do
	./ex24 <$f || echo "err: ${f}"
done
