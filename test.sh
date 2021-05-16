#!/usr/bin/env bash
set -euxo pipefail

tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT

EXE="$(readlink -f $(dirname "$0"))/rename-exchange"

cd "$tmp"
mkdir a
touch a/orig_a
mkdir b
touch b/orig_b

: should error on too-few arguments
! "$EXE"
! "$EXE" a

: should error on too-many arguments
! "$EXE" a a a

: should present help
"$EXE" --help | grep usage

: should replace directories
"$EXE" a b
test -f a/orig_b
test -f b/orig_a
