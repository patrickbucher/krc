#!/usr/bin/env bash

make ex08

test "$(echo '...' | ./ex08)" = '---' || echo "err: three fullstops"
test "$(echo 'This is a test.' | ./ex08)" = 'This is a test-' || echo "err: fullstop at the end"
