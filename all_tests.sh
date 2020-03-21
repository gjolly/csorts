#!/bin/bash

VALGRIND_REPORT="./valgrind_report.txt"

RETURN=0
for s in insertion selection merge heap; do
  SORT_ALGO="$s" ./run_test.sh || RETURN=1
  echo
  echo
done

cat "${VALGRIND_REPORT}"

exit $RETURN
