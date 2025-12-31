#!/usr/bin/env bash

set -euo pipefail

make ex03

test $(./ex03 a-z) = 'abcdefghijklmnopqrstuvwxyz' || echo "err: a-z"
test $(./ex03 a-z0-9) = 'abcdefghijklmnopqrstuvwxyz0123456789' || echo "err: a-z0-9"
test $(./ex03 a-c0-2) = 'abc012' || echo "err: a-c0-2"
test $(./ex03 a-c-e) = 'abcde' || echo "err: a-c-e"
test $(./ex03 -a-z) = 'abcdefghijklmnopqrstuvwxyz' || echo "err: a-c-e"
test $(./ex03 A-C4-7a-f) = 'ABC4567abcdef' || echo "err: A-C4-7a-f"
