#!/usr/bin/env bash

test() {
    local test_operator="$1"
    local test_file="$2"
    local expected="$3"
    local got

    printf "test: %s:\t" "$(basename "$test_file")"
    printf "expected: "
    [ "$test_operator" = "not equal" ] && printf "!"
    printf "%s\t" "$expected"
    got=$(./pbrain-gomoku-ai < "$test_file")
    got=$(printf "%s\n" "$got" | tail -n 1)
    printf "got: %s\t" "$got"
    if [ "$test_operator" = "equal" ]; then
        if [ "$expected" = "$got" ]; then
            printf "PASSED\n"
        else
            printf "ERROR\n"
        fi
    else
        if ! [ "$expected" = "$got" ]; then
            printf "PASSED\n"
        else
            printf "ERROR\n"
        fi
    fi
}

test equal       tests/priority_attack  15,10
test equal       tests/priority_defence 7,7
test "not equal" tests/priority_emile   7,1
test equal       tests/play_2_combinaison   4,2
