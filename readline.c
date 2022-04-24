/************************************************
 * Program name: readline.c
 * Student name: Anh Luu
 * This is the implementation file for functions
 * in readline.h.
 ***********************************************/

#include "readline.h"

/**************************************
 * read_line: Gets user input from console
 * via getchar() and discards any leading spaces.
 * Repeats until a newline character is seen.
 * If a user enters in more than n characters
 * only the first n are saved.
 **************************************/
int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
