/*************************************
 * Program name: request.c
 * Student name: Anh Luu
 * This program implements the request
 * and linked list related functions
 * defined in request.h.
 *************************************/

#include "request.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*******************************************
 * search_in_list: Returns the request in the input list
 * that matches to split, which is an array of
 * three strings for each field in the user's profile. 
 * Returns NULL if there is no such match.
 ******************************************/
struct request *search_in_list(struct request *list, char split[][100]) {

    if (list == NULL) {
        return NULL;
    }
    struct request *ptr = list;

    while (ptr != NULL) {
        if (strcmp(ptr->last, split[0]) == 0 && strcmp(ptr->first, split[1]) == 0 && strcmp(ptr->email, split[2]) == 0) {
            return ptr;
        }
        ptr = ptr->next;
    }

    // Not found
    return NULL; 
}

/*******************************************
 * append_to_list: Interacts with the user to
 * have them enter in information for a new 
 * request. Creates a new request and appends
 * it to the list of requests, list.
 * Returns the modified list.
 ******************************************/
struct request *append_to_list(struct request *list) {
    int i, j, ctr;
    j = 0;
    ctr = 0;
    printf("Enter lastName, FirstName, email (in the same order)");
    char str[200];
    read_line(str, 200);
    char split[4][100];
    for (i = 0; i <= (strlen(str)); i++) {
        // if space or NULL found, assign NULL into split[ctr]
        if (str[i] == ' ' || str[i] == '\0') {
            split[ctr][j] = '\0';
            ctr++;  //for next word
            j = 0;  //for next word, init index to 0
        } else {
            split[ctr][j] = str[i];
            j++;
        }
    }

    // Now split[0] has last name split[1] has first name and split [2] has email

    // Now , we need to first search if the detials already exist

    if (search_in_list(list, split) == NULL) {
        // element not found
        int ag;
        printf("element not found... adding element \n");
        printf("Enter Age");
        scanf("%d", &ag);

        struct request *temp = (struct request *)malloc(sizeof(struct request));
        strcpy(temp->last, split[0]);
        strcpy(temp->first, split[1]);
        temp->age = ag;
        strcpy(temp->email, split[2]);
        strcpy(temp->status, "pending");
        temp->next = NULL;

        // Now if list is empty

        if (list == NULL) {
            list = temp;
            return list;
        } else {
            struct request *p = list;
            while (p->next != NULL) {
                p = p->next;
            }
            // Now p is at the last node
            p->next = temp;
            return list;
        }

    } else {
        printf("Element already Exists");
        return list;
    }

    return list;
}

/*******************************************
 * update: Interacts with user to update an existing
 * request in the list of stored requests. If unable
 * to find a matching request to be updated, does
 * not perform an update.
 ******************************************/
void update(struct request *list) {
    int i, j, ctr;
    j = 0;
    ctr = 0;
    printf("Enter lastName, FirstName, email , new status (in the same order)");
    char str[200];
    read_line(str, 200);
    char split[4][100];
    for (i = 0; i <= (strlen(str)); i++) {
        // if space or NULL found, assign NULL into split[ctr]
        if (str[i] == ' ' || str[i] == '\0') {
            split[ctr][j] = '\0';
            ctr++;  //for next word
            j = 0;  //for next word, init index to 0
        } else {
            split[ctr][j] = str[i];
            j++;
        }
    }

    // Now split[0] has last name split[1] has first name and split [2] has email split 3 has new status

    // Now , we need to first search if the detials already exist
    struct request *data = search_in_list(list, split);
    if (data != NULL) {
        // we need to update
        strcpy(data->status, split[3]);
    } else {
        printf("The record does not exist in the list");
    }
}

/*******************************************
 * print_list: Displays all of the requests
 * in our list.
 ******************************************/
void print_list(struct request *list) {

    struct request *p = list;
    while (p != NULL) {
        printf("\nFirst Name: %s\nLast Name: %s\nEmail: %s\nAge: %d\nStatus: %s\n", p->first, p->last, p->email, p->age, p->status);
        printf("***************************\n");
        p = p->next;
    }
}

/*******************************************
 * clear_list: Frees all nodes in the request
 * list
 ******************************************/
void clear_list(struct request *list) {

    struct request *p = list;

    while (p != NULL) {
        struct request *nxt = p->next;
        free(p);
        p = nxt;
    }
}
