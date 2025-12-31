#!/usr/bin/env bash

make ex05

test $(./ex05 255 16) = 'ff' || "err: 255 16"
test $(./ex05 255 8) = '377' || "err: 255 8"
test $(./ex05 255 2) = '11111111' || "err: 255 2"
