#!/usr/bin/env bash

make ex07

test "$(echo '...' | ./ex07)" = 'FULLSTOPFULLSTOPFULLSTOP' || echo "err: three fullstops"
test "$(echo 'This is a test.' | ./ex07)" = 'This is a testFULLSTOP' || echo "err: fullstop at the end"
