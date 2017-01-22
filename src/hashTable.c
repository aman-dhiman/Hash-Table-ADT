#include "linkedListH.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node ** createTable(node * head) {
    node ** hTable;
    int hSize;

    hSize = (int) (newNode->pNumber) *2 / 3;
    if (hSize %2 == 0) {
        hSize = hSize + 1;
    }
    hTable = malloc (sizeof (node *) * hSize);
    hashFunc (hTable, head);
    return (hTable);
}

void hashFunc (node ** hTable, node * head) {
    node * current;
    node * temp;
    int index;

    current = head->next;

    while (current != NULL) {
        index = (int) (current->pNumber) % hSize;
        if (hTable[index] == NULL) {
            hTable[index] = current;
        }
        else
        {
            temp = hTable[index];
            while (temp->side != NULL) {
                temp = temp->side;
            }
            temp->side = current;
        }
        current = current->next;
    }
}

void lookup (node ** hTable, int hSize, long pNum) {
    int index;
    node * current;

    index = (int) (pNum) % hSize;
    current = hTable[index];
    while (current != NULL) {
        if (current->pNumber == pNum) {
            printf ("PhoneNumber: %ld\n", pNum);
            printf ("First Name: %s\n", current->fName);
            printf ("Last Name: %s\n", current->lName);
            break;
        }
        current = current->side;
    }
    if (current->pNumber != pNum) {
        printf ("Entry not found\n");
    }
}

void addEntry (node ** hTable, int hSize, node * head) {
    int index;
    long pNum;
    char firstN[50];
    char lastN[50];
    node * temp;
    node * current;
    temp = head->next;

    printf ("Please enter the phone number:\n");
    scanf ("%ld", &pNumber);
    printf ("Please enter the First name:\n");
    scanf ("%s", firstN);
    printf ("Please enter the Last name:\n");
    scanf ("%s", lastN);
    addSorted (newNode, pNumber, firstN, lastN);

    hashFunc (hTable, head);
}
