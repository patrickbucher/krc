#!/usr/bin/env bash

make ex04

test $(./ex04 12345) = '12345' || echo "err: 12345"
test $(./ex04 123456) = '123456' || echo "err: 123456"
test $(./ex04 -12345) = '-12345' || echo "err: -12345"
test $(./ex04 -2147483648) = '-2147483648' || echo "err: INT_MIN"
