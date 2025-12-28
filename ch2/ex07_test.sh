#!/usr/bin/env bash

set -euo pipefail

make ex07

# invert(1010, 2, 2) == 1100
# invert(10, 2, 2) == 12
test $(./ex07 10 2 2) -eq 12 || echo "err: invert(10, 2, 2)"

# invert(10101010, 6, 7) == 11010101
# invert(170, 6, 7) == 213
test $(./ex07 170 6 7) -eq 213 || echo "err: invert(170, 6, 7)"

# invert(10000001, 5, 4) = 10111101
# invert(129, 5, 4) = 189
test $(./ex07 129 5 4) -eq 189 || echo "err: invert(129, 5, 4)"

# invert(11111111, 5, 3) = 11000111
# invert(255, 5, 3) = 199
test $(./ex07 255 5 3) -eq 199 || echo "err: invert(255, 5, 3)"
