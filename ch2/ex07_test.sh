#!/usr/bin/env bash

set -euo pipefail

make ex07

# invert(11111111, 5, 3) = 11000111
# invert(255, 5, 3) = 199
test $(./ex07 255 5 3) -eq 199 || echo "err: invert(255, 5, 3)"

# invert(10000001, 5, 4) = 10111101
# invert(129, 5, 4) = 189
test $(./ex07 129 5 4) -eq 189 || echo "err: invert(129, 5, 4)"
