# csorts

Implementing all the sort algorithms in C. You can find the algorithms in [sorting.c](sorting.c).

## Testing
Test functions should be written if file ending with `_test.c`. Use `test.h` to find the tools to build (`assert`, `fail`...) your test. Run your test using [run_test.sh](run_test.sh).

```bash
$ ./run_test.sh
Compiling with SORT_ALGO=merge

SUCCES: basic
SUCCES: basic2
SUCCES: basic3
SUCCES: empty
SUCCES: hundred
SUCCES: characters
```

If you want to run only a set of tests, you can pass an expression to the script:
```bash
$ ./run_test.sh basic
Compiling with SORT_ALGO=merge

SUCCES: basic
SUCCES: basic3
```

