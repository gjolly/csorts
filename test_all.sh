#!/bin/bash

set -e

./build_tests.sh
make -B test > /dev/null
./test

