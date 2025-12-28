#!/bin/bash

BASE_DIR="07-strings"

declare -A folders
folders=(
  ["00-basic"]="string_length string_copy string_concat string_compare string_reverse string_palindrome count_vowels count_consonants count_digits count_spaces"
  ["01-character"]="toggle_case uppercase lowercase char_frequency first_non_repeating first_repeating remove_duplicates max_occurring_char min_occurring_char is_digit_string"
  ["02-word"]="word_count longest_word shortest_word reverse_words word_frequency remove_extra_spaces capitalize_words replace_word anagram_check sort_words"
  ["03-embedded"]="custom_strlen custom_strcpy custom_strcmp custom_strcat string_to_int int_to_string tokenizer split_string buffer_overflow_safe_copy remove_comments"
  ["04-tricky"]="balanced_parentheses rotation_check substring_search permutation_count pattern_matching run_length_encoding string_compression longest_unique_substring edit_distance wildcard_matching"
)

mkdir -p "$BASE_DIR"

for folder in "${!folders[@]}"; do
    DIR="$BASE_DIR/$folder"
    mkdir -p "$DIR"

    i=0
    for file in ${folders[$folder]}; do
        printf -v num "%02d" $i
        FILE="$DIR/${num}-${file}.c"

        cat <<EOF > "$FILE"
/*
 * File Name   : ${num}-${file}.c
 * Folder      : $BASE_DIR/$folder
 *
 * Description :
 *  TODO: Describe the problem statement.
 *
 * Input :
 *  TODO: Define input.
 *
 * Output :
 *  TODO: Define expected output.
 *
 * Requirements :
 *  - Use standard C
 *  - Avoid library functions unless specified
 *  - Follow Embedded C coding standards
 *
 * Author      : Pravin Jogdand
 */

#include <stdio.h>

int main(void)
{
    /* TODO: Implement logic here */

    return 0;
}
EOF
        ((i++))
    done
done

echo "✅ String program folder structure created successfully!"

