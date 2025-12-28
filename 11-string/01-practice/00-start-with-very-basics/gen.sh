#!/bin/bash

DIR="basic_strings"
mkdir -p $DIR

programs=(
"print_each_char"
"print_char_ascii"
"print_ascii_only"
"print_capital_ascii"
"print_small_ascii"
"capital_to_small"
"small_to_capital"
"string_to_lowercase"
"string_to_uppercase"
"check_alphabet"
)

descriptions=(
"Print each character of a string using loop"
"Print each character and its ASCII value"
"Print ASCII values of characters in string"
"Print capital letters and their ASCII values"
"Print small letters and their ASCII values"
"Convert a capital letter to small letter using ASCII"
"Convert a small letter to capital letter using ASCII"
"Convert entire string to lowercase"
"Convert entire string to uppercase"
"Check whether given character is an alphabet"
)

i=0
for prog in "${programs[@]}"
do
    filename=$(printf "%02d-%s.c" $i $prog)

    cat <<EOF > $DIR/$filename
/*
 * File Name   : $filename
 * Folder      : basic_strings
 *
 * Description :
 *  ${descriptions[$i]}
 *
 * Requirement :
 *  - Use loops where applicable
 *  - Do not use string library functions
 *  - Use ASCII value logic
 *  - Follow Embedded C coding standards
 *
 * Input :
 *  - Hardcoded string / character
 *
 * Output :
 *  - Printed characters / ASCII values / converted output
 *
 * Author      : Pravin Jogdand
 */

#include <stdio.h>

int main(void)
{
    /* Sample data */
    char str[] = "AbC123";
    char ch = 'A';

    /*
     * TODO:
     * Implement logic here as per requirement
     */

    return 0;
}
EOF

    ((i++))
done

echo "✅ 10 basic string programs generated in '$DIR' directory"

