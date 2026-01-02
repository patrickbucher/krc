#!/usr/bin/env bash

make ex02

test "$(./ex02 1)" = '1.000000' || echo "err: 1"
test "$(./ex02 -1)" = '-1.000000' || echo "err: -1"
test "$(./ex02 1.5)" = '1.500000' || echo "err: 1.5"
test "$(./ex02 -1.5)" = '-1.500000' || echo "err: -1.5"
test "$(./ex02 33.125)" = '33.125000' || echo "err: 33.125"
test "$(./ex02 -33.125)" = '-33.125000' || echo "err: -33.125"
test "$(./ex02 1e0)" = '1.000000' || echo "err: 1e0"
test "$(./ex02 1e1)" = '10.000000' || echo "err: 1e1"
test "$(./ex02 1e-1)" = '0.100000' || echo "err: 1e-1"
test "$(./ex02 '1.23e1')" = '12.300000' || echo "err: 1.23e1"
test "$(./ex02 '123.45e-2')" = '1.234500' || echo "err: 123.45-e2"
test "$(./ex02 '123.45E-2')" = '1.234500' || echo "err: 123.45-E2"
