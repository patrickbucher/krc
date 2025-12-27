#!/usr/bin/env bash

set -euo pipefail

make ex06

# setbits(0, 0, 0, 1) = 0
test $(./ex06 0 0 0 1) -eq 0 || echo "err: setbits(0, 0, 0, 1)"

# setbits(11011011, 3, 4, 1100) = 11011100
# setbits(219, 3, 4, 12) = 220
test $(./ex06 219 3 4 12) -eq 220 || echo "err: setbits(219, 3, 4, 12)"

# setbits(10001111, 6, 3, 111) = 11111111
# setbits(143, 6, 3, 7) = 255
test $(./ex06 143 6 3 7) -eq 255 || echo "err: setbits(143, 6, 3, 7)"

# setbits(10101111, 5, 1, 1110) = 10001111
# setbits(175, 5, 1, 14) = 143
test $(./ex06 175 5 1 14) -eq 143 || echo "err: setbits(175, 5, 1, 14)"
