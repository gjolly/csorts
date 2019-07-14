#!/bin/bash

for s in insertion selection merge heap; do
  SORT_ALGO="$s" ./run_test.sh
  echo
  echo
done
