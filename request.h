/*****************************************************
 * Program name: request.h
 * Student name: Anh Luu
 * This file defines all of the functions and structs
 * used to implement our linked list of requests
 * and functions to perform modifications on the
 * list.
 ****************************************************/

#ifndef REQUEST_H
#define REQUEST_H
#include <stdio.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30

struct request {
    char first[NAME_LEN + 1];
    char last[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    int age;
    char status[STATUS_LEN + 1];
    struct request *next;
};

// Descriptions for functions found in request.c
struct request *append_to_list(struct request *list);
void update(struct request *list);
void print_list(struct request *list);
void clear_list(struct request *list);
int read_line(char str[], int n);

#endif //REQUEST_H
