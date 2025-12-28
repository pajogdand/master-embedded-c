/*
 * File Name   : 09-sort_words.c
 * Folder      : 07-strings/02-word
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

void sort_words(char words[][20], int count)
{
    int i, j;
    char temp[20];

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            int k = 0;
            while (words[i][k] != '\0' && words[j][k] != '\0' && words[i][k] == words[j][k]) {
                k++;
            }
            if (words[i][k] > words[j][k]) {
                // Swap words[i] and words[j]
                int m = 0;
                while (words[i][m] != '\0') {
                    temp[m] = words[i][m];
                    m++;
                }
                temp[m] = '\0';

                m = 0;
                while (words[j][m] != '\0') {
                    words[i][m] = words[j][m];
                    m++;
                }
                words[i][m] = '\0';

                m = 0;
                while (temp[m] != '\0') {
                    words[j][m] = temp[m];
                    m++;
                }
                words[j][m] = '\0';
            }
        }
    }
}
int main(void)
{
    char words[][20] = {"apple", "banana", "cherry", "date"};
    int count = 4;

    sort_words(words, count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
