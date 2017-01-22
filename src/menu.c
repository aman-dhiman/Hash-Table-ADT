#include "linkedListH.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readParse (int argc, char * argv, node * newNode) {
    char string [115];
    char * token;
    char fName [50];
    char lName [50];
    long pNum;
    FILE * pBook = fopen (argv, "r");

    if (argc != 2) {
        exit (0);
    }
    printf("\033[2J");

    if (pBook != NULL) {
        while (fgets (string, 115, pBook) != NULL) {
            token = strtok (string, ",");
            strcpy (fName, token);
            token = strtok (NULL, ",");
            strcpy (lName, token);
            pNum = atol (strtok (NULL, ","));
            printf ("%s %s: %ld\n", fName, lName, pNum);;
            addSorted (newNode, pNum, fName, lName);
        }
        fclose (pBook);
        printf ("\n\nFile successfully read\n");
    }
    else printf ("File could not be read\n");
    printf ("\nPress Enter to go to the main menu\n");
    getchar();
}

void printScreen () {
    printf("\033[2J");
    printf ("       Hash Table Menu       \n");
    printf ("\nChoose one of the following options by typing in the\n"
            "number in front of them or enter 'q' to quit\n\n");
    printf ("1. Load up a file\n");
    printf ("2. Add an entry\n");
    printf ("3. Lookup an entry using the phone number\n");
    printf ("4. Print the entire list\n");
}

void lookup (node * newNode, long pNum) {
    node * temp = newNode;
    printf("\033[2J");
    while ((temp->next != NULL) && (temp->pNumber != pNum)) {
        temp = temp->next;
    }
    if (temp->pNumber == pNum) {
        printf ("Phone Number: %ld\nFirst Name: %s\nLast Name: %s\n",
                temp->pNumber, temp->fName, temp->lName);;
    }
    else printf ("No entry found for that number.\n");
    printf ("\nPress Enter to go to the main menu\n");
    getchar();
}

void addEntry (node * newNode) {
    int count;
    long pNumber;
    char firstN[50];
    char lastN[50];
    printf("\033[2J");

    count = (int) newNode->pNumber;
    printf ("Please enter the phone number:\n");
    scanf ("%ld", &pNumber);
    printf ("Please enter the First name:\n");
    scanf ("%s", firstN);
    printf ("Please enter the Last name:\n");
    scanf ("%s", lastN);
    addSorted (newNode, pNumber, firstN, lastN);
    if (((int)(newNode->pNumber)) == count + 1) {
        printf ("Entry successfully added.\n");
    }
    else printf ("Entry could not be added.\n");
    printf ("\nPress Enter to go to the main menu\n");
    getchar();
}
