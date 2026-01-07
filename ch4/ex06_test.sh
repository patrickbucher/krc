#!/usr/bin/env bash

make ex06

test "$(./ex06 12 wa 3 wb ra rb /)" = '4.000' || echo "err: divide a and b"
test "$(./ex06 13 wa 17 wb 3 4 + ra + rb +)" = '37.000' || echo "err: add a and b"
test "$(./ex06 8 wa 3 wb ra rb + print r_ 5 +)" = '11.000 16.000' || echo "err: add 8 and _"
