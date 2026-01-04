#!/usr/bin/env bash

make ex04

test "$(./ex04 3 2 + print 2 '*')" = '5.000 10.000' || echo "err: print"
test "$(./ex04 3 dup +)" = '6.000' || echo "err: dup"
test "$(./ex04 3 8 swap -)" = '5.000' || echo "err: swap"
test "$(./ex04 3 2 + clear 1 2 +)" = '3.000' || echo "err: clear"
