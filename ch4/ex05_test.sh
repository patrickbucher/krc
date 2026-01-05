#!/usr/bin/env bash

make ex05

test "$(./ex05 20 25 + sin)" = '0.851' || echo "err: sin 45"
test "$(./ex05 25 20 + cos)" = '0.525' || echo "err: cos 45"
test "$(./ex05 1 1 + exp)" = '7.389' || echo "err: exp 2"
test "$(./ex05 1 1 + 3 pow)" = '8.000' || echo "err: pow 2 3"
