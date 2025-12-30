#!/usr/bin/env bash

set -euo pipefail

make ex02

expected_escaped=$(cat ./ex02_test_escaped.txt)
expected_unescaped=$(cat ./ex02_test_unescaped.txt)

actual_escaped=$(./ex02 escape "$expected_unescaped")
actual_unescaped=$(./ex02 unescape "$expected_escaped")

test "$actual_escaped" = "$expected_escaped" || echo "err: escape"
test "$actual_unescaped" = "$expected_unescaped" || echo "err: unescape"
