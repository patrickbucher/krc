#!/usr/bin/env bash

make ex03

set -euo pipefail

test "$(./ex03 1 1 +)" = '2.000' || echo "err: 1 1 +"
test "$(./ex03 8 3 -)" = '5.000' || echo "err: 8 3 -"
test "$(./ex03 3 4 '*')" = '12.000' || echo "err: 3 4 '*'"
test "$(./ex03 12 4 /)" = '3.000' || echo "err: 12 4 /"
test "$(./ex03 1 1 + 10 +)" = '12.000' || echo "err: 1 1 + 10 +"
test "$(./ex03 1 2 - 4 5 + '*')" = '-9.000' || echo "err: 1 2 - 4 5 + '*'"
test "$(./ex03 13 2 \%)" = '1.000' || echo "err: 13 2 \%"
