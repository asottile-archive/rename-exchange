# ARCHIVED

it is feature complete and I don't plan on updating it further

___

[![Build Status](https://github.com/asottile/rename-exchange/actions/workflows/main.yml/badge.svg)](https://github.com/asottile/rename-exchange/actions)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/asottile/rename-exchange/main.svg)](https://results.pre-commit.ci/latest/github/asottile/rename-exchange/main)

rename-exchange
===============

a tiny wrapper around `renameat2(...)` and `RENAME_EXCHANGE` to do
**atomic (directory) replacement**

### building

#### precompiled

see [the releases tab] for precompiled binaries.

[the releases tab]: https://github.com/asottile/rename-exchange/releases

#### with musl

smaller, static

```bash
musl-gcc -O3 -s -static main.c -o rename-exchange
```

#### with classic gcc

larger, dynamically linked

```bash
gcc -O3 -s main.c -o rename-exchange
```

### support

as this uses `renameat2(...)` it can only be used on linux>3.15

### usage

```console
$ ls -l foo bar
bar:
total 0
-rw-r--r-- 1 asottile asottile 0 May 16 13:35 wat

foo:
total 0
-rw-r--r-- 1 asottile asottile 0 May 16 13:35 wat2

$ rename-exchange foo bar

$ ls -l foo bar
bar:
total 0
-rw-r--r-- 1 asottile asottile 0 May 16 13:35 wat2

foo:
total 0
-rw-r--r-- 1 asottile asottile 0 May 16 13:35 wat
```
