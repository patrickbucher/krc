#!/usr/bin/env bash

make ex06

test "|$(./ex06 12345 5)" = '|12345' || echo "err: 12345 5"
test "|$(./ex06 -12345 6)" = '|-12345' || echo "err: -12345 6"
test "|$(./ex06 12345 10)" = '|     12345' || echo "err: 12345 10"
test "|$(./ex06 -12345 10)" = '|    -12345' || echo "err: -12345 10"
