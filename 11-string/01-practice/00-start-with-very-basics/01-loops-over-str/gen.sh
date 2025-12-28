#!/bin/bash

DIR="string_loops"
mkdir -p $DIR

programs=(
"print_each_char"
"print_string_while"
"string_length"
"count_characters"
"reverse_print"
"string_copy"
"count_vowels"
"count_consonants"
"count_spaces"
"count_digits"
"upper_to_lower"
"lower_to_upper"
"toggle_case"
"count_words"
"check_palindrome"
"compare_strings"
"char_frequency"
"remove_vowels"
"replace_space_underscore"
"reverse_inplace"
"count_lowercase"
"count_uppercase"
"first_occurrence"
"remove_duplicates"
"count_special_chars"
"only_digits_check"
"longest_word_length"
"remove_spaces"
"print_ascii"
"count_repeated_chars"
)

i=0
for prog in "${programs[@]}"
do
    filename=$(printf "%02d-%s.c" $i $prog)

    cat <<EOF > $DIR/$filename
/*
 * File Name   : $filename
 * Folder      : string_loops
 *
 * Description :
 *  Write a C program to implement "$prog"
 *  using loops over string.
 *
 * Requirement :
 *  - Use loop (for / while)
 *  - Do not use string library functions unless specified
 *  - Handle null-terminated strings
 *  - Follow Embedded C coding standards
 *
 * Input :
 *  - Hardcoded string or user input
 *
 * Output :
 *  - Expected output as per problem statement
 *
 * Author      : Pravin Jogdand
 */

#include <stdio.h>

int main(void)
{
    char str[] = "sample_string";

    /* TODO:
     * Implement logic here
     */

    return 0;
}
EOF

    ((i++))
done

echo "✅ 30 string loop program files created in '$DIR' directory"

