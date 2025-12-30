#!/usr/bin/env bash

set -euo pipefail

make ex02

export f=/tmp/ex02.txt
./ex02 "this\tis\ta\ttest" >$f && test $(cat $f) = "this\\tis\\ta\\ttest" || "err: tabs"
./ex02 "this\nis\na\ntest" >$f && test $(cat $f) = "this\\nis\\na\\ntest" || "err: newlines"
