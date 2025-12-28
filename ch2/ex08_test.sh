#!/usr/bin/env bash

set -euo pipefail

make ex08

# rightrot(1010, 2) == 10
# rightrot(10, 2) == 2
test $(./ex08 10 2) -eq 2 || echo "err: rightrot(10, 2)"

# rightrot(10110100, 4) == 1011
# rightrot(180, 4) == 11
test $(./ex08 180 4) -eq 11 || echo "err: rightrot(180, 4)"
