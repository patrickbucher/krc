#!/usr/bin/env bash

make ex01

test "$(./ex01 whatever ever)" -eq 4 || echo "err: whatever ever"
test "$(./ex01 whateve ever)" -eq -1 || echo "err: whateve ever"
test "$(./ex01 thisissinister is)" -eq 9 || echo "err: thisissinister is"
